Fitting
=======

Fitting Library for geodetic problems.

First Steps
-----------

Look into \bin and \example.

~~~
MAN-PAGE:

 Fitting v1.0.1 12.01.2010 F. Kern (www.i3mainz.fh-mainz.de)
 Programm fuer die Approximation von geometrischen Formen.

 Aufruf: D:\SRC\SRC_A\kalib\fitting.exe <daten> [Optionen] 
 Optionen:
  -T<type>   : Art der Ausgleichsfigur
        type = 'plane'   | 'Ebene'   : Ausgleichsebene
             = 'circle'  | 'Kreis'   : Ausgleichskreis
             = 'sphere'  | 'Kugel'   : Ausgleichskugel
             = 'ellipse' | 'Ellipse' : Ausgleichsellipse
  -C<threshold>  : Kriterium fuer Konvergenz (1e-09)
  -N<name>       : Projektname
  -f<Format> : Format der Eingabezeilen festlegen.
               moegliche Bestandteile von <Format> sind:
                    'p' Punktnummer       'x' X-Koordinate
                    '.' Spalte ueberlesen  'y' Y-Koordinate
                    'c' Punktcode         'z' Z-Koordinate
                    (Default '-fxyz ')
  -D<level>  : Debuging-Level [0-5]
  -o<name>   : Name der Ausgabedatei
                        <x> muss [x] kann angegeben werden. (x) Default
~~~
