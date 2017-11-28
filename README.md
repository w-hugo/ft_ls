# ft_ls
---
This project aims to reproduce the BSD command ls, with few options

| option | description |
| ---: | :----|
| -a | Include directory entries whose names begin with a dot (.). |
| -d | Directories are listed as plain files (not searched recursively). |
| -f | Output is not sorted.  This option turns on the -a option. |
| -l | Print output in long format. |
| -g | owner name is supressed to match POSIX compatibility. |
| -G | Enable colorized output. Default to true if -l option is set. |
| -r | Reverse the order of the sort. |
| -R | Recursively list subdirectories encountered. |
| -t | Sort by time modified. |


#### Clone the repository and compile with
```bash
 $> make -j
```


#### Usage:
```bash
 $> ./ft_ls [-adflgGrRt] [file ...]
```

#### Author
Hugo Weber
huweber@student.42.fr
