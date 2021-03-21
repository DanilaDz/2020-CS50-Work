from cs50 import get_string
import math


def main():
    
    # gets text from user
    text = get_string('Text: ').upper()
    letters = 0
    words = 1
    sentences = 0
    
    # counts letters
    for letter in text:
        if letter >= 'A' and letter <= 'Z':
            letters += 1
    
    # counts words
    for word in text:
        if word == ' ':
            words += 1
    
    # counts sentences
    for sentence in text:
        if sentence == '.' or sentence == '!' or sentence == '?':
            sentences += 1
    
    # does liau formula
    L = float(letters / words * 100)
    S = float(sentences / words * 100)
    liau = int(round(0.0588 * L - 0.296 * S - 15.8))
    
    # checks for grade level
    if liau < 1:
        print("Before Grade 1")
    
    elif liau >= 16:
        print("Grade 16+")
    
    else:
        print("Grade ", liau)


main()
