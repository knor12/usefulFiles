
import os.path
from pathlib import Path

#read file and convert it into a byte array for c language

def readFilePrintHexArray(filePath):
    numbers_perLine = 16
    st =''
    my_file = Path(filePath)
    if my_file.is_file():
        print(f'file {filePath} doesnt exist.')
              
    with open(filePath, 'rb') as f:
        st += 'const uint8_t bytes[]={\n'
        counter = 0
        while 1:
            byte_s = f.read(1)
            if not byte_s:
                break
            byte = byte_s[0]
            counter+=1
            if (counter % numbers_perLine)==0:
                st+="\n"
            if counter > 1:
                st+=","
            st+="0x%0.2X" % byte #(format(byte, '#x')) #f'{byte}'

        st += '\n};'

    return st


if __name__ == '__main__':
    st = readFilePrintHexArray('file.bin')
    print(st)
