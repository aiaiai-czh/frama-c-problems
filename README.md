This work is a modified version of the original [frama-c-problems](https://github.com/manavpatnaik/frama-c-problems) dataset. [AutoSpec](https://sites.google.com/view/autospecification) added corresponding calling functions and assertions for each function in this dataset in its experiments to determine whether the LLMs can generate correct specifications for that function. We have improved on this work, and the main additions are as follows:
- Add the missing specifications in the original version to ensure full verification.
- Based on the AutoSpec's version, modify the called function and improve the verification of the behavior of the called function.
- Delete duplicate and meaningless functions.

There is only the file "loops/4.c" and I don't know how to write the corresponding ACSL specfications. If anyone knows, please bring it up on the issue page.

This work can serve as a usable dataset for learning how to use frama-c or for conducting related experiments.

Please note that the original version of this dataset might have added some incorrect function call to reflect the rigor of the specification. However, this work is to write the correct specification for the function so that it can pass the verification. Therefore, in some programs, we have removed some function calls that would cause the function to fail the verification.

# Software Environment
| SoftWare | Version |
| :---: | :---: |
| frama-c | 29.0 (Copper) |
| Alt-Ergo | 2.6.0 |
| Z3 | 4.13.4 |
| os | Ubuntu 22.04.1 LTS |

# How to Use
Enter the directory of the file you want to verify and execute the following command:
```sh
frama-c -wp -wp-precond-weakening -wp-no-callee-precond -wp-prover Alt-Ergo,Z3 -wp-print -wp-timeout 8 [path-to-file]
```