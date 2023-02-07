### Pipe
```
CMD1 | CMD2
```
 - here `CMD1`'s output will be redirect to `CMD2`
    - Example has been given in `Head/Tail` section.

### Head/Tail
```
head -10 FILE.txt
```
 - Print the first `n` lines from `FILE.txt`
    - for this command the `n=10`, so first 10 lines

 ```
 tail -10 FILE.txt
 ```
 - Print the last `n` lines from `FILE.txt`
    - for this command the `n=10`, so first 10 lines


> One of the most important command. Need to self study.


#### Get Lines with Range
```
head -20 FILE.txt | tail -5
```
 - Print the `15 to 20` lines from `FILE.txt`
    - Using Pipe, can be done with multiple files as well.

### Find/Grep
#### **$grep**

```
grep TEXT/PATTERN FILE.txt
```
 - `TEXT/PATTERN` will be returned from `FILE.txt` file. 
    - `Text/Pattern` is case-sensitive.
    - `-n` will also show the line numbers.
    - `-i` for case-insensitive.
    - `-c` for count total matches.
        - _will only return line count, NOT TEXT._
    - `-E PATTERN` for regular expression input.

<br> 


#### **$find**
```
find -type f -name "FILE.txt"
```
 - Will search for files with name `FILE.txt`

```
find -type d -name "FOLDER"
```
 - Will search for folders with name `FOLDERS`

```
find SEARCH_DIR -type f -name "FILE.txt"
```
 - It's same as previous file search except the file will be searched inside `SEARCH_DIR`.
 - Regular Expression also can be used in the name or `FILE.txt` or `SEARCH_DIR`.

> `-user USERNAME` will search files/folders owned by that specific user.
 <br>


#### Regular Expression
```
grep -n -E [0-9] -i CMDs.md
```
 - Anything with numbers

```
grep -n -E [0-9]* -i CMDs.md
```
 - Everything but highlight the numbers. (Just like TOC)

```
grep -n -E [0-9]+ -i CMDs.md
```
 - Lines with at least one number.

```
grep -n -E 01[0-9]{9} -i CMDs.md
```
 - Text which is starts with `01` and contains `numbers` and additional `9` lenghts.
    > Basically, Phone numbers

<br> 

 - `find` search for file/directory.
 - `grep` search for text/pattern/content.
> `Regular Expression` is very important and needs to self study. 
> More options are specified in the lab manuals.

<br>

### User/Group
```
useradd USER_NAME
```
 - Adds an user with name `USER_NAME`
    - However needs to add `sudo` get superuser permission.
    ```
    sudo useradd USER_NAME
    ```

    > `sudo` means `Super USer Do`

<br>


```
userdel USER_NAME
```
 - Removes user named `USER_NAME`.

<br>

```
sudo passwd USER_NAME
```
 - Change/Set Passwords for user `USER_NAME`.

```
su USERNAME
```
 - Switch user to `USERNAME`

<br>

#### **Add/Remove Group**
```
groupadd GROUP_NAME
```
 - Creates group with name `GROUP_NAME`.

```
groupdel GROUP_NAME
```
 - Removes group with name `GROUP_NAME`.


#### **Add/Change User to a Group**
```
sudo usermod -g GROUP_NAME USER_NAME
```
 - Add/Change `USER_NAME` to `GROUP_NAME` group.


### Permission
#### **Ownership**
 > Owner [`u`] - Creator of the file/folder.

 > Owner [`u`] - Users who belongs to same group as the creator.

 > All Others [`o`] - Other than the above 2 types.

<br>

#### **Permission**
 > Read [`r`] [`4`]

 > Write [`w`] [`2`]

 > Execute [`x`] [`1`]

```
FILE.txt -rwx r-x --x
```
 - FILE.txt `u` `g` `o`

<br>

#### **Change Permission**
```
chmod g+x FILE.txt
```
 - add execution for the `g` to `FILE.txt`

```
chmod 743 FILE.txt
```
 - Here the permission has been modded for user, group and all others.
    - `Digits` are for `u`, `g` and `o`.
    - 7 means all permission [ 4 + 2 + 1]
    - ... and so on