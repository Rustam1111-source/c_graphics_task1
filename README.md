# mirzaev_rm

1. create an empty public github repo 
2. copy this repo to your repo(all except .git/)
3. сomplete the task (edit code in src/).
4. check build and tests
```
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --verbose
```
5. add your ID on top of README.md 
(surname + initials, e.g. magomedov_mm)
6. commit and push (dont commit build/)
7. open Actions and check the pipeline (build + test)
