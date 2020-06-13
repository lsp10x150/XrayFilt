#!/bin/bash

gnuplot -persist <<-EOFMarker
     plot "initialSpectra.dat" with linespoints

EOFMarker
