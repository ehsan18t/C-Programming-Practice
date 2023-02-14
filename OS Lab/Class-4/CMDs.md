### For Each Loop
Format
```
for VAR in LIST
    do
        statement
    done
```
 - Iterate through all items in `LIST` array.

<br>

Example Code:
```
arr=(1 2 3)
for x in ${arr[@]}
    do
        echo $x
    done
```
 - `@` indicates all elements.
 - Array in bash declared using `()` and no need for comma `,`.

<br>

### For Loop
Format
```
for (( expr1; expr2; expr3 ))
    do
        statement
    done
```
 - Normal For loop

<br>

Example Code
```
arr=(1 2 3)
for (( i=0; i<${#arr[@]}; i++ ))
    do
        echo "${arr[i]}"
    done
        
```

<br>

### Functions
Format
```
functon_name() {
    statements
}
```

Example Code
```
test() {
    echo "Test"
}

# Function Call
test
```

<br>

Function with Args
```
test() {
    echo "$1"
}

# Function Call
test "Test"
```

### Return Value from Function
 - Variables in bash are globally declared. Even the variables in functions are accessible from outside of the function. Because the shell itself is works like funtion. So, this is one way to get return.
 - That means the variables can be override by function call.

 ```
 func() {
    var="test"
 }

 echo $var
 ```

 - Another way to return is perform `echo` and call the function with `$`.

 ```
 func() {
    echo "test"
 }

 var="$(func)"

 echo $var

 ```


### Command line args in functions
 - Generally the scpoe of function are different. So, only way to pass script args to function is to pass them with `$*` in function argument.

```
func_name $*
``` 
