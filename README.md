# csci3453-lab3-pagereplacement
simulation of page replacement algorithms

installation

1. clone this repository
2. `cd/lab3`
3. `make`
4. `./lab3` returns the expected error:
```usage: % lab3 num_frames input_file output_file```
5. run `./lab3` with 
  - a power of 2 for `num_frames`, 
  - a file with 10,000 lines such as testData.txt for `input_file`,
  - a filename to write the output to

sample output:
```
==============================================================
  Page Replacement Algorithm Simulation (num frames = 256)
==============================================================
                                    Page fault ratio
  Algorithm Total page faults 2000  4000  6000  8000  10000
--------------------------------------------------------------
  LRU           5032          0.521 0.514 0.507 0.507 0.503
  Optimal       2150          0.308 0.252 0.229 0.223 0.215
  ```

consider viewing the accompanying [essay](https://github.com/robfitzgerald/csci3453-lab3-pagereplacement/blob/master/lab3/lab3.pdf)

this was produced for UC Denver Undergraduate Operating Systems class.
