### List Files
```
ls
```
 - `-l` -> long listing (More Details)
 - `~/FOLDER` -> Listing that folder

### Present Directory (Print Working Directory)
```
pwd
```

### Change Directory
```
cd DIR_NAME
```
 - `cd ..` takes 1 directory back
 - to go to child dir no `/` or `~` or `.` needed
   - `/` represent absolute path, others are relative path
 - `.` means current directory

### Make Directory
```
mkdir DIR_NAME
```

 - `/` represent `root` dir
 - `~` represents `User Home` dir
   - `/home/user1/Downloads` == `~/Downloads`

### OS/Kernel Name
```
uname
```
 - To view full info `-a` needs to be included.

### User Name
```
whoami
```

### Print Text
```
echo "TEXT HERE"
```

### Append to FIle
```
echo "Some Text" >> FILE_NAME.txt
```

### Write to File
```
echo "Some Text" > FILE_NAME.txt
```

### Concat and View Texts
#### To only View
```
cat FILE_NAME.txt
```
 - Other text CLI editor can also be used like `vim` or `nano`.
   - `nano FILE_NAME.txt` or `vim FILE_NAME.txt`
#### To Concat and View
```
cat FILE1.txt FILE2.txt
```
 - with `>` or `>>` theses concanated texts can be output to file.

### Remove Directory
```
rmdir DIR_NAME
```
 - only removes empty folder

### Create File
```
touch FILE_NAME.txt
```

### Remove File/Folder
```
rm FILE_NAME.txt
```
 - to force remove any file/folder `rm -r FILE_FOLDER_NAME`
   - `-r` represent recursive
   - `-rf` represent force recursively

### Edit Text Files with Editors
```
vi FILE_NAME.txt
```
or
```
gedit FILE_NAME.txt
```
or
```
nano FILE_NAME.txt
```
and so on...

### Copy Files
```
cp SRC DEST
```
 - `cp file1.txt ~/Downloads/file1.txt`

### Move Files
```
mv SRC DEST
```
 - `cp file1.txt ~/Downloads/file1.txt`

### Rename File
```
mv SRC DEST
```
 - `cp file1.txt file2.txt`

### View Manual
```
man CMD
```
 - shows manual of the command
   - `man cp` or `man mv`

