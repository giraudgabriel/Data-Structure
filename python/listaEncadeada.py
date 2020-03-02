class Node(object):
    def __init__(self, conteudo, proximo = None):
        super(Node, self).__init__()
        self.conteudo = conteudo
        self.proximo = proximo
        self.aux = None

    def printAll(self, aux = None):
        self.aux = aux if aux != None else self.proximo
        if(self.aux != None):
            print(aux.conteudo)
            self.printAll(aux.proximo)
        else: print(self.conteudo)


lista = Node(19)
lista = Node(20, lista)
lista.printAll()
