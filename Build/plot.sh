#!/bin/bash

gnuplot -persist <<-EOFMarker
     plot "spectrum.dat" with linespoints

EOFMarker
