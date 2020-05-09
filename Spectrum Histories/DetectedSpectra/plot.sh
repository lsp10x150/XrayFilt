#!/bin/bash

gnuplot -persist <<-EOFMarker
     plot "spectrum 3mm Al.dat" with linespoints, "spectrum 1mm Al.dat" with linespoints

EOFMarker
