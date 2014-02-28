#pragma option -v+
#pragma verboselevel 9

#define Debug

#define AppVersion "1.0.1"

#define AppName "Fitting"

;=============================
#define WITH_SRC
;#define WITH_LINUX
;=============================

[Setup]
AppName={#AppName} {#AppVersion}
AppVerName={#AppName} {#AppVersion}
#ifdef WITH_SRC
OutputBaseFilename=fitting_{#AppVersion}_src_setup
#else
OutputBaseFilename=fitting_{#AppVersion}_setup
#endif
InfoAfterFile=install/fitting/readme.{#AppVersion}.txt
InfoBeforeFile=install/fitting/infobeforeinstall.{#AppVersion}.txt
AppCopyright=(c) Fredie Kern

PrivilegesRequired=none
;AdminPrivilegesRequired=no
DefaultDirName={pf}\fitting
DefaultGroupName=fitting
;SetupIconFile={app}\xdesy.exe
UninstallDisplayIcon={app}\fitting.exe
DisableStartupPrompt=yes
;WizardImageFile=Tb_Logo.bmp
WizardImageBackColor=clRed
; MessagesFile=compiler:German-2.isl
; uncomment the following line if you want your installation to run on NT 3.51 too.
; MinVersion=4,3.51
;Compression=zip/9
;Compression=bzip/9
;Compression=lzma/max
Compression=lzma/ultra
;SolidCompression=yes

[Languages]
Name: mytrans; MessagesFile: compiler:Languages/German.isl

[Types]
Name: full; Description: Vollständige Installation
Name: compact; Description: Minimale Installation
Name: custom; Description: Benutzerdefinierte Installation; Flags: iscustom

[Components]
#ifdef WITH_SRC
Name: main; Description: Erforderliche Dateien; Types: full compact custom
Name: source; Description: Quellcode; Types: full compact custom
#else
Name: main; Description: Erforderliche Dateien; Types: full compact custom; Flags: fixed
#endif
Name: documents; Description: Dokumentation; Types: full custom
Name: examples; Description: Beispiele; Types: full custom
; Name: additional; Description: Software anderer Autoren; Types: full custom

#ifdef WITH_LINUX
Name: linux; Description: Linux (binaries); Types: full custom
#endif

[Files]
Source: fitting.exe; DestDir: {app}; Components: main
Source: fitting.man; DestDir: {app}; Components: main

Source: Debug\fitting.exe; DestDir: {app}\src\fitting\Debug; Components: main
Source: Release\fitting.exe; DestDir: {app}\src\fitting\Release; Components: main


Source: install\fitting\readme.1.0.1.txt; DestDir: {app}; Components: main
Source: install\fitting\lizenz.txt; DestDir: {app}; Components: main

Source: install\fitting\readme.1.0.1.txt; DestDir: {app}\doc; Components: documents
Source: install\fitting\lizenz.txt; DestDir: {app}\doc; Components: documents
Source: fitting.man; DestDir: {app}\doc; Components: documents

Source: fitting_examples\run_it.bat; DestDir: {app}\examples; Components: examples
Source: fitting_examples\bopp.circle; DestDir: {app}\examples; Components: examples
Source: fitting_examples\bopp.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\bopp.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick.circle; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_01.ellipse; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_01.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_01.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_02.ellipse; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_02.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\derletztekick_02.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_gut.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_gut.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_gut.txt; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_schlecht.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_schlecht.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\ellipse1_schlecht.txt; DestDir: {app}\examples; Components: examples
Source: fitting_examples\jaeger.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\jaeger.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\jaeger.sphere; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand.pts; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand_uvw.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand_uvw.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\kreisrand_uvw.pts; DestDir: {app}\examples; Components: examples
Source: fitting_examples\linda.ellipse; DestDir: {app}\examples; Components: examples
Source: fitting_examples\linda.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\linda.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\niemeier_1135.erg; DestDir: {app}\examples; Components: examples
Source: fitting_examples\niemeier_1135.log; DestDir: {app}\examples; Components: examples
Source: fitting_examples\niemeier_1135.plane; DestDir: {app}\examples; Components: examples



#ifdef WITH_SRC

Source: ../util/getopt.h; DestDir: {app}\src\util; Components: source
Source: ../util/Getopt.cpp; DestDir: {app}\src\util; Components: source
Source: ../util/microtim.h; DestDir: {app}\src\util; Components: source
Source: ../util/microtim.cpp; DestDir: {app}\src\util; Components: source
Source: ../util/iskeyword.h; DestDir: {app}\src\util; Components: source
Source: ../util/iskeyword.cpp; DestDir: {app}\src\util; Components: source
Source: ../util/rho.h; DestDir: {app}\src\util; Components: source
Source: ../util/rho.cpp; DestDir: {app}\src\util; Components: source
Source: ../util/mystring.h; DestDir: {app}\src\util; Components: source
Source: ../util/mystring.cpp; DestDir: {app}\src\util; Components: source

Source: fitting_main.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_it.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_it.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_plane.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_plane.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_circle.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_circle.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_sphere.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_sphere.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_ellipse.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_ellipse.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_matrix.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_matrix.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_approxfunc.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_approxfunc.cpp; DestDir: {app}/src/fitting; Components: source
Source: cfitting_util.h; DestDir: {app}/src/fitting; Components: source
Source: cfitting_util.cpp; DestDir: {app}/src/fitting; Components: source


Source: fitting.bdsproj; DestDir: {app}\src/fitting; Components: source
Source: fitting.bpf; DestDir: {app}\src/fitting; Components: source
Source: fitting.res; DestDir: {app}\src/fitting; Components: source

Source: fitting.vcproj; DestDir: {app}\src/fitting; Components: source
Source: fitting.sln; DestDir: {app}\src/fitting; Components: source


Source: fitting-install.iss; DestDir: {app}\src/fitting; Components: source


#endif

[Icons]
Name: {group}\Fitting; Filename: {app}\fitting.exe; Flags: dontcloseonexit
;Name: {userdesktop}\Xdesy; Filename: {app}\xdesy.exe


[Registry]

[Run]

[UninstallDelete]
Type: files; Name: {app}\examples\*.*
Type: files; Name: {app}\src\*.*
Type: files; Name: {app}\*.*

Type: dirifempty; Name: {app}
