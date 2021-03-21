from cs50 import get_int


def main():
    
    while True:
        height = get_int('Height:')
        if height >= 1 and height <= 8:
            break
    
    # prints spaces before hashes
    for i in range(height):
        for j in range(height - i - 1):
            print(' ', end='')

        # prints hashes for first row 
        for n in range(i+1):
            print('#', end='')

        # prints the double space between the pyramids
        print('  ', end='')

        # prints the last pyramid of hashes
        for m in range(i+1):
            print('#', end='')
        print('')
            
main()
