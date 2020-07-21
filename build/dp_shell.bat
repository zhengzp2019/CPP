@echo off
:again
makedata#.exe > input
bubble_sort.exe < input > output_my
select_sort.exe <input> output_other
fc output_my output_other
if not errorlevel 1 goto again
pause
