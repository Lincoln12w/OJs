inputs = raw_input()
outputs = raw_input()
i = 0
j = 0
brokens = ''
while i < len(inputs) and j < len(outputs):
    value = inputs[i]
    if value != outputs[j]:
        key = value.upper()
        if brokens.find(key) == -1:
            brokens += key
    else:
        j +=1
    i += 1

print brokens
