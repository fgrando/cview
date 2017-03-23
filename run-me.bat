@echo off
SET PATH=%PATH%;graphviz-2.38\release\bin
SET PATH=%PATH%;%cd%

rem ./pycflow2dot.py -i input.c -f pdf -x excluded.txt -o output_dir

call cmd /k "echo example: pycflow2dot.py -i input.c -f pdf -x excluded.txt -o output_dir/out "