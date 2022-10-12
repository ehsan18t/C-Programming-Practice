#!/usr/bin/python
import os

# Configs
remove_ext_less = True  # remove files without ext
include_ext = ["exe", "bin"]  # Remove File Types
ignore_list = [".git", ".vscode", "placeholder"]  # Ignore Files/Folders from Scanning
dir_name = os.getcwd()  # Current Directory


# Functions
def run_fast_scandir(dir, ignore=[], inc_ext=[], remove_ext_less=False):
    subfolders, files = [], []

    for f in os.scandir(dir):
        if f.name not in ignore:
            if f.is_dir():
                subfolders.append(f.path)
            elif f.is_file():
                ext = f.name.split('.')[-1]
                if (ext == f.name and remove_ext_less) or (ext in inc_ext):
                    files.append(f.path)

    for dir in list(subfolders):
        sf, f = run_fast_scandir(dir, ignore, inc_ext, remove_ext_less)
        subfolders.extend(sf)
        files.extend(f)
    return subfolders, files


def delete_file(filename):
    if os.path.exists(filename) and not os.path.isdir(filename) and not os.path.islink(filename):
        os.remove(filename)


# Main
sf, file_list = run_fast_scandir(dir_name, ignore_list, include_ext, remove_ext_less)

for item in file_list:
    print(f"-> Removing \"{item}\"")
    delete_file(os.path.join(dir_name, item))
