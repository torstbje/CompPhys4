# Getting Started

## Prerequisites
Check that you have g++-12 the GNU compiler installed if you are on macOS by running
```sh
g++-12 --version
```
if not, install by running
```sh
brew install gcc@12
```
Check also that you have Python3 installed by running
```sh
python3
```
## How to Run
The compilation and execution are both governed by the makefile. To reproduce the results presented in the report, simply run the following command at terminal under `src` folder. 
Note that the text files in `textfiles/` and `.out` output will be deleted after execution. For alternative execution options, see [later session](#session).
### Mac users:
```sh
make all-mac
```

To keep output files run
```sh
make all-mac-c
```
to keep the output file and the text files.

### Windows and Linux users:
```sh
make all
```

### Alternative Runs
- To compile
```sh
make compile
```
- To remove text files and the output file.
