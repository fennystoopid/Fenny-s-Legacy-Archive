family = ['hi', 'mother', 'father', ['halmeoni', 'grandpa']]

#family2 = ['bye', 'mother', 'father', ['halmeoni', 'grandpa']]
#print(len[family])

family[0] = 'bye'
family[2] = 'dad'
family[3][0] = 'halmeoni'
family[3][-1] = 'grandpa'
family[1] = 'mom'

print(family)

family[0] = 'hi'
family[2] = 'father'
family[3][0] = 'halmeoni'
family[3][-1] = 'grandpa'
family[1] = 'mother'

print(family)