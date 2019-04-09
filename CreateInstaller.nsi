; BanchouCRC.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install BanchouCRC.nsi into a directory that the user selects.
;
; in !define ARCH, please select 32 or 64 depending your detsination processor.

!define BANCHOUVER "2.0.0"
!define ARP "Software\Microsoft\Windows\CurrentVersion\Uninstall\BanchouCRC"
!define ARCH "32"

!include "MUI2.nsh"
!include "FileFunc.nsh"

!insertmacro MUI_PAGE_LICENSE "LICENSE"
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_LANGUAGE "SpanishInternational"

;--------------------------------

; The name of the installer
Name "BanchouCRC"

; The file to write
OutFile "BanchouCRC-${BANCHOUVER}-Win${ARCH}.exe"

; The default installation directory
InstallDir $PROGRAMFILES${ARCH}\BanchouCRC

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\BanchouCRC" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------

; Pages

;Page components
;Page directory
;Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

;Version Information

  VIProductVersion "${BANCHOUVER}.0"
  VIAddVersionKey "ProductName" "BanchouCRC"
  VIAddVersionKey "CompanyName" "David Kantun"
  VIAddVersionKey "FileDescription" "xdelta3 GUI"
  VIAddVersionKey "FileVersion" "${BANCHOUVER}"
  VIAddVersionKey "LegalCopyright" ""

;--------------------------------

; The stuff to install
Section "BanchouCRC (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File /r "..\build-BanchouCRC-Desktop_Qt_5_12_2_MinGW_${ARCH}_bit-Release\release\*"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\BanchouCRC "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "${ARP}" "DisplayName" "BanchouCRC"
  WriteRegStr HKLM "${ARP}" "DisplayVersion" "${BANCHOUVER}"
  WriteRegStr HKLM "${ARP}" "Publisher" "David Kantun"
  WriteRegStr HKLM "${ARP}" "DisplayIcon" '"$INSTDIR\BanchouCRC.exe"'
  WriteRegStr HKLM "${ARP}" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "${ARP}" "NoModify" 1
  WriteRegDWORD HKLM "${ARP}" "NoRepair" 1
  
  ${GetSize} "$INSTDIR" "/S=0K" $0 $1 $2
  IntFmt $0 "0x%08X" $0
  WriteRegDWORD HKLM "${ARP}" "EstimatedSize" "$0"
  WriteUninstaller "$INSTDIR\uninstall.exe"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\BanchouCRC"
  CreateShortcut "$SMPROGRAMS\BanchouCRC\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortcut "$SMPROGRAMS\BanchouCRC\BanchouCRC.lnk" "$INSTDIR\BanchouCRC.exe" "" "$INSTDIR\BanchouCRC.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "${ARP}"
  DeleteRegKey HKLM SOFTWARE\BanchouCRC

  ; Remove files and uninstaller
  Delete $INSTDIR\*
  RMDir /r $INSTDIR\iconengines
  RMDir /r $INSTDIR\imageformats
  RMDir /r $INSTDIR\platforms
  RMDir /r $INSTDIR\styles
  RMDir /r $INSTDIR\translations
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\BanchouCRC\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\BanchouCRC"
  RMDir "$INSTDIR"

SectionEnd
