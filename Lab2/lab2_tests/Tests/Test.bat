@echo off
@echo Test %2
@echo Test %2 >> result.txt
copy %2 path.in >> nul
timer %1 2000 65536 >> result.txt
check %2 %2.a path.out >> result.txt
if exist path.in del path.in
if exist path.out del path.out