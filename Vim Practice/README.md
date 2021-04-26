# Beginner Vim Cheatsheet
### Mode
* `ESC` / `Ctrl + [` - Normal Mode
* `a` - Insert Mode (After Current Char)
* `i` - Insert Mode (Before Current Char)
* `v` - Visual Mode / Selection Mode
* `:` - Command Mode

### Arrow
* `h` - Left arrow
* `l` - Right arrow
* `j` - Down arrow
* `k` - Up arrow

### Jump / Hop
#### **`Word`**
* `e` - Last char before space
* `w` - Next word (first char)
* `b` - Previous word (first char)
* `ge` - Previous Word (last char)
* `*` - Next same word
* `#` - Previous same word
#### **`Line`**
* `0` - Start of the line
* `^` - Start of the line (after whitespace)
* `$` - End of the line
* `gg` - First line
* `G` - Last line
* `:n` - Goto n line
* `nG` - Goto n line
#### **`Window`**
* `zz` - Center this line
* `zt` - Top this line
* `zb` - Bottom this line
* `H` - Top of screen
* `M` - Middle of screen
* `L` - Bottom of screen
#### **`Tab`**
* `:tabclose` - Close current tab
* `:tabfirst` - First tab
* `:tablast` - Last tab
* `:tabn` - Next tab
* `tabp` - Previous tab

### Select
* `ve` - Select untill next space
* `vw` - Select untill next word
* `V` - Select current line
* `v` - Select current char

### Copy
* `yy` - Copy current line
* `y` - Copy selected (Only in visual mode)
* `yw` - Copy word
* `yj` - Copy current and previous line
* `yk` - Copy current and next line
