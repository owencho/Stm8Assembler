# Stm8Assembler
## Introduction
This is STM 8 assembler function which convert STM 8 assembly code into STM8 machine code.
The main function for this STM 8 assmbler is getInstruction() function which return the machine mode when user feed the assembly language code into the function.
The tokenizer that used inside this STM8 Assembler to retrieve the instruction and operand token is based on the TokenizerSkeleton [2] that created by [chaosAD](https://github.com/chaosAD).
The format of the machine code is based on [1] which is PM0044.pdf file that has all instruction details. 

## Required software to execute this STM8Assembler
1. Ceedling 
2. MSYS32/64
3. Atom or other relevant editor **(For source code editing only)**
4. Cosmic STM8 Software Development tools ([Software Link](https://www.cosmic-software.com/stm8.php))
5. Git
6. CodeLite **(For Debugging)**



## How to clone the file from GitHUB
```
git clone https://github.com/owencho/Stm8Assembler
```
or you can download from GitHUB webpage //add picture here


## Updating the STM8Assembler
```
cd Stm8Assembler  //if you are not inside the project folder
git fetch         // to fetch the data from GitHUB
git pull         // to pull the data and combine into the project folder
```
**Recommended to update STM8Assembler to ensure best user experience and updated module**



























## Appendix
1. https://www.st.com/content/ccc/resource/technical/document/programming_manual/43/24/13/9a/89/df/45/ed/CD00161709.pdf/files/CD00161709.pdf/jcr:content/translations/en.CD00161709.pdf
2. https://github.com/chaosAD/TokenizerSkeleton
