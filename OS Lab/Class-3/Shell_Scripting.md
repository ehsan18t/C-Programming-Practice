### File Extension
> File extension must be `sh`

### Script Indicator
```
#!/bin/bash
```
 - First line of the script must be this line above for bash.

### Comment
```
# This is a comment
```
 - Lines that Start with `#` are considered comment.

### Change Permission Mode
```
chmod +x FILE.sh
```
 - Permission mode needs to change for the first time.
 - Here, we've added excution permission so that the system can understand this file needs to excute.

### Variable Declarations
```
var_name="Something"
echo $var_name
```
 - We are assigning `Something` to `var_name` variable.
 - Here, before and after assignment operator `=` there shouldn't be any space or the script won't work.

<br>

#### **Special Case for Quotations**
Double Quote
```
var_name="Something"
echo "$var_name"
```

output
```
Someting
```

<br>

Single Quote

```
var_name="Something"
echo '$var_name'
```

output
```
$var_name
```


### Input
```
read var1
echo "Read Input $var1"
```
 - It will ask user for input in terminal.
 - Anythng we read wll be input as `string`.

### Arithmetic
```
num= expr 1 + 2
echo $num
```
 - Here, after the `=` everything will be separated by space.
 - For multiplication `*` won't work we have to use `\*`.

Or, we can use Back Tick ` ` ` sign for the work like below,
```
num=`expr 1 + 2`
echo $num
```
 - In this case, only the inside back tick part will be separated by space and before and after `=` sign there will be no space.

Direct Print
```
echo "`expr 1 + 2`"
```
 - It will also print 3.

Arithmetic with Variables
```
num=`expr 1`
x=`expr $num + 1`
```


### Conditions
Format
```
if [ condition ]; then
    statement
elif [ condition2 ]; then
    statement2
else
    statement3
fi
```
 - `eq` - Euqal
 - `gt` - Greater than
 - `lt` - Less than
 - `ge` - Greater than equal
 - `le` - Less than equal
 - `ne` - Not equal

<br>

Example Script of finding bigger number
```
#!/bin/bash

echo "Enter first Number: "
read num_1

echo "Enter second Number: "
read num_2

if [ $num_1 -gt $num_2 ]; then
    echo "$num_1 is bigger."
elif [ $num_1 -lt $num_2 ]; then
    echo "$num_2 is bigger."
else
    echo "Both numbers are equal."
fi
```

### File Conditions
 - `-d file` -- True if the file is directory
 - `-f file` -- True if the file is file
 - `-e file` -- True if the file is exist. Usally not used, better use `-f` and `-d`.
 - `-g file` -- True if set-group-id is set on file
 - `-r file` -- True if the file is readable
 - `-s file` -- True if the file has non-zero size
 - `-u file` -- True if set-user-id set on file
 - `-w file` -- True if the file is writable
 - `-x file` -- True if the file is executable

### Arguments
 - `$*` - Command line argiments
 - `$#` - Number of arguments
 - `$N` - Nth argument in `$*`. Starts from 1.

<br>

Example Script of finding bigger number with arguments
```
#!/bin/bash

num_1=$1
num_2=$2

if [ $num_1 -gt $num_2 ]; then
    echo "$num_1 is bigger."
elif [ $num_1 -lt $num_2 ]; then
    echo "$num_2 is bigger."
else
    echo "Both numbers are equal."
fi
```
