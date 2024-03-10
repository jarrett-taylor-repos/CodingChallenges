f = open("C:/Users/Jarret/source/repos/jarrett-taylor-repos/CodingChallenges/DataAnnotation/text.txt")

dict = {}
length = 0

for x in f:
    num = x.split(' ')[0]
    word = x.split(' ')[1].strip()

    dict[num] = word
    length += 1


step = 1
curr = 1
phrase = ''
while(curr <= length):
    if(curr != 1):
        phrase += ' '
    phrase += str(dict.get(str(curr)))
    step+=1 
    curr+=step

print(phrase)


