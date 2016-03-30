class listNode:
    def __init__(self, myaddr, value, nextaddr):
        self._myaddr = myaddr
        self._value = value
        self._nextaddr = nextaddr
    def setValue(self,value):
        self._value = value
    def setAddr(self,nextaddr):
        self._nextaddr = nextaddr
    def getValue(self):
        return self._value
    def getAddr(self):
        return self._nextaddr
    def getMyaddr(self):
        return self._myaddr

def printNodeList(nodeList, initialAddr):
    node = listNode('', '', initialAddr)
    while node.getAddr() != '-1':
        addr = node.getAddr()
        node = nodelist[int(addr)]
        print "%s %s %s" %(addr, node.getValue(), node.getAddr())

def inttostr5bit(addr):
    address = ''
    if addr / 10000 == 0:
        address += '0'
    if addr / 1000 == 0:
        address += '0'
    if addr / 100 == 0:
        address += '0'
    if addr / 10 == 0:
        address += '0'
    address += str(addr)
    return address

def printNewList(nodelists):
    n = len(nodelists) - 1
    for i in range(0, n):
        print "%s %s %s" %(inttostr5bit(nodelists[i].getMyaddr()), nodelists[i].getValue(), inttostr5bit(nodelists[i + 1].getMyaddr()))

    print "%s %s %s" %(inttostr5bit(nodelists[n].getMyaddr()), nodelists[n].getValue(), '-1')

initial = raw_input().split()

initialaddr = int(initial[0])
nodescnt = int(initial[1])
shift = int(initial[2])

nodelist = []
node = listNode(0,0,0)
for i in range(0, 100000):                          # enough for all nodes
    nodelist.append(node)
for i in range(0, nodescnt):
    node = raw_input().split()
    nodeaddr = int(node[0])
    nodelist[nodeaddr] = listNode(int(node[0]),int(node[1]), int(node[2]))

'''
newinitialaddr = initial[0]
if shift != 1:
    times = nodescnt / shift
    nextaddr = initial[0]
    preaddr = '-1'
    for i in range(0, times):
        initialaddr = int(nextaddr)                 # start a new reverse
        previousaddr = '-1'                         
        for j in range(0, shift):
            currentaddr = nextaddr                  # currentaddr point to the current node
            if(j == shift - 1):
                prepreaddr = currentaddr
            node = nodelist[int(currentaddr)]
            nextaddr = node.getAddr()               # save the address of next node
            nodelist[int(currentaddr)].setAddr(previousaddr)
            previousaddr = currentaddr
        nodelist[initialaddr].setAddr(nextaddr)
        if preaddr != '-1':
            nodelist[int(preaddr)].setAddr(prepreaddr)
        else:
            newinitialaddr = prepreaddr
        preaddr = initialaddr

printNodeList(nodelist, newinitialaddr)
'''

node = listNode(0,0,initialaddr)
newlist = []
while node.getAddr() != -1:
    addr = node.getAddr()
    node = nodelist[addr]
    newlist.append(node)                            # sorted list

if shift != 1 and shift != 0:
    times = len(newlist) / shift
    for i in range(0, times):
        index1 = i * shift
        index2 = (i + 1) * shift - 1
        while index1 < index2:
            temp = newlist[index1]
            newlist[index1] = newlist[index2]
            newlist[index2] = temp
            index1 += 1
            index2 -= 1

printNewList(newlist)

