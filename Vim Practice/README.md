<div align="center">
<h1 align="center">Vim Cheatsheet for Beginners</h1>
<Strong>These commands are tested in VSCode with Vim plugin.</strong>
</div>

&nbsp;
### 💠 Mode
* `ESC` / `Ctrl + [` - Normal Mode
* `a` - Insert Mode (After Current Char)
* `i` - Insert Mode (Before Current Char)
* `v` - Visual Mode / Selection Mode
* `:` - Command Mode

&nbsp;
### 💠 Arrow
* `h` - Left arrow
* `l` - Right arrow
* `j` - Down arrow
* `k` - Up arrow

&nbsp;
### 💠 Search
* `/pattern` - Search forward
* `?pattern` - Search backward
* `n` - Repeat search forward
* `N` - Repeat search backward

&nbsp;
### 💠 Jump
**`🔹 Char (Inside Current Line)`**
* `fc` - Go forward to character `c`
* `Fc` - Go backward to character `c`
* `tc` - Go forward before character `c`
* `Tc` - Go backward before character `c`
* `;` - Go forward next
* `,` - Go backward next

<br>

**`🔹 Word`**
* `e` - Last char before space
* `w` - Next word (first char)
* `b` - Previous word (first char)
* `ge` - Previous Word (last char)
* `*` - Next same word
* `#` - Previous same word

<br>

**`🔹 Current Line`**
* `0` - Start of the line
* `^` - Start of the line (after whitespace)
* `I` - Start of the line and insert (after whitespace)
* `$` - End of the line
* `A` - End of the line and insert

<br>

**`🔹 Line`**
* `o` - Next line and insert
* `O` - Previous line and insert
* `gg` - First line
* `G` - Last line
* `:n` - Goto n line
* `nG` - Goto n line

<br>

**`🔹 Block / Paragraph`**
* `{` - Move up
* `}` - Move down
* `%` - Jump between braces (`(` `)`, `{` `}`, `[` `]`)

<br>

**`🔹 Window / Page`**
* `zz` - Center this line
* `zt` - Top this line
* `zb` - Bottom this line
* `H` - Top of screen
* `M` - Middle of screen
* `L` - Bottom of screen
* `Ctrl + u` - Page up (Half page)
* `Ctrl + d` - Page down (Half page)

<br>

**`🔹 Tab`**
* `:tabclose` - Close current tab
* `:tabfirst` - First tab
* `:tablast` - Last tab
* `:tabn` - Next tab
* `tabp` - Previous tab

&nbsp;

### 💠 Select
* `ve` - Select until next space
* `vw` - Select until next word (Highlight word)
* `V` - Select current line
* `v` - Select current char (Highlight char)

&nbsp;

### 💠 Copy
* `y` - Copy selected (Only in visual mode)
* `yy` - Copy current line
* `yw` - Copy current word
* `yj` - Copy current and previous line
* `yk` - Copy current and next line

&nbsp;

### 💠 Editing
**`🔹 Paste`**
* `p` - Paste next 
* `P` - Paste Previous

<br>

**`🔹 Delete`**
* `x` - Delete current char
* `s` - Delete current char and insert
* `cw` - Delete all char before space and insert (from cursor)
* `dw` - Delete until next word
* `diw` - Delete current word
* `X` - Delete current word and insert (Custom `bdwi`)
* `dd` - Delete current line
* `S` - Delete current line and insert
* `D` - Delete the rest of the line
* `C` - Delete the rest of the line and insert 

<br>

**`🔹 Undo/Redo`**
* `u` - Undo changes
* `Ctrl + r` - Redo


<br>


### 💠 Exit
* `:q` - Close file
* `:q!` - Close file, abandon changes
* `:qa` - Close all files
* `:qa!` - Close all files, abandon changes
* `:w` - Save changes
* `:wq` / `:x` - Save and close file
* `ZZ` - Save and quit
* `ZQ` - Quit without checking changes

<br>


### 💠 Notes & Combos
* All keys mentioned above can be combined with one another.
    * Example: `ct)` can delete everything until `)`. That means it can be used for clear function parameter or something like that. Here `c` means `cut` and `t)` means forward until char `)`.
* `di{` - Delete everything inside `{}`
* `d2i{` - Delete everything inside `{}` and its surround `{}`.
* `ct}` - Delete everything until `}` and insert.
* `v5$d` - Delete next 5 lines including current.
* `cip` - Delete paragraph and insert
* `di(` - Delete everything inside `()`
* `yi(` - Copy everything inside `()`
* `vi(` - Highlight everything inside `()`
* `diw` - Delete current word

&nbsp;
### 💠 Important VSCode Configurations for New Users

&nbsp;

**🔹 Disable Vim `ctrl+c` `ctrl+v` `ctrl+x` commands**
```json
"vim.useCtrlKeys": true,
"vim.handleKeys": {
		"<C-c>": false,
		"<C-x>": false,
		"<C-v>": false
	}
```

&nbsp;

**🔹 Disable Vim arrow controls**
```json
"vim.handleKeys": {
		"<": false,
		">": false
    }
```

&nbsp;

**🔹 Enable `jj` to `Normal Mode`**
```json
"vim.insertModeKeyBindingsNonRecursive": [
        {
            "before": ["j", "j"],
            "after": ["<esc>"]
        }
    ]
```
&nbsp;

**🔹 Enable `X` to `Delete Current Word and Insert`**
```json
"vim.normalModeKeyBindings": [
        {
            "before": ["X"],
            "after": ["b","d","w","i"]
        }
    ]
```
&nbsp;

**🔹 Enable vim to use `System Clipboard`**
```json
"vim.useSystemClipboard": true
```
