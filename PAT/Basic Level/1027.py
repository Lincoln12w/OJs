inputs = raw_input()

n = int(inputs.split()[0])
c = inputs[len(inputs)-1]

# total = (1 + 3 + ... + 2n-1) * 2 - 1 = 2*n*n - 1
stage = (n + 1) / 2
stage = int(stage ** 0.5)
left = n - stage * stage * 2 + 1
for i in range(stage - 1, 0, -1):
    print ' ' * (stage - i - 1) + c * (2 * i + 1)
for i in range(0, stage):
    print ' ' * (stage - i - 1) + c * (2 * i + 1)

print left
