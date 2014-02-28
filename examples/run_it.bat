set FITTING=..\fitting.exe
%FITTING% bopp.circle               -Tcircle  -obopp.erg                2>bopp.log                             
%FITTING% derletztekick.circle      -Tcircle  -oderletztekick.erg 	2>derletztekick.log 
%FITTING% derletztekick_01.ellipse  -Tellipse -oderletztekick_01.erg 	2>derletztekick_01.log 
%FITTING% derletztekick_02.ellipse  -Tellipse -oderletztekick_02.erg 	2>derletztekick_02.log 
%FITTING% ellipse1_gut.txt          -Tellipse -oellipse1_gut.erg 	2>ellipse1_gut.log 
%FITTING% ellipse1_schlecht.txt     -Tellipse -oellipse1_schlecht.erg 	2>ellipse1_schlecht.log
%FITTING% jaeger.sphere             -Tsphere  -ojaeger.erg 		2>jaeger.log 
%FITTING% kreisrand_uvw.pts         -Tcircle  -okreisrand_uvw.erg 	2>kreisrand_uvw.log 
%FITTING% kreisrand.pts             -Tellipse -okreisrand.erg 		2>kreisrand.log 
%FITTING% linda.ellipse             -Tellipse -olinda.erg 		2>linda.log 
%FITTING% niemeier_1135.plane       -Tplane   -oniemeier_1135.erg 	2>niemeier_1135.log 