import os
import zipfile as zf

for file in os.listdir():
    if zf.is_zipfile(file):
        year: str = file[:4]
        month: str = file[5:7]
        zf.ZipFile(file).extract(f"k_d_t_{month}_{year}.csv")
input("Done")
