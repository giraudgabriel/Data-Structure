
using System;
using System.Collections.Generic;

namespace ListaEncadeada
{
    public class Node
    {
        public Node next;
        public object data;
    }

    public class LinkedList
    {
        private Node head;

        public void PrintAllNodes()
        {
            Console.WriteLine("\n Valores da Lista Encadeada:\n");
            Node aux = head;
            while (aux != null)
            {
                Console.WriteLine(aux.data);
                aux = aux.next;
            }
            Console.WriteLine();
        }

        public void AddFirst(object data)
        {
            Node inserted = new Node
            {
                data = data,
                next = head
            };

            head = inserted;
        }

        public void AddLast(object data)
        {
            if (head == null)
            {
                head = new Node
                {
                    data = data,
                    next = null
                };
            }
            else
            {
                Node inserted = new Node
                {
                    data = data
                };

                Node current = head;
                while (current.next != null) current = current.next;

                current.next = inserted;
            }
        }

        public object Find(object data)
        {
            Console.WriteLine($"- Buscando por {data}... \n");
            Node aux = head;
            while (aux != null)
            {
                if (aux.data == data)
                {
                    Console.WriteLine("\t Encontrado! \n");
                    return aux;
                }
                aux = aux.next;
            }
            Console.WriteLine("\t Não Encontrado! \n");
            return null;
        }

        public void FindAndRemove(object data)
        {
            Node toRemove = (Node)Find(data);
            if (toRemove != null)
            {
                toRemove.data = toRemove.next;
                Console.WriteLine($"\n {data} removido com sucesso! \n");
            }
        }

        public void AddList(LinkedList list)
        {
            Node aux = list.head;

            while (aux != null)
            {
                AddLast(aux.data);
                aux = aux.next;
            }
        }

        public void Distinct()
        {
            Node previous = head;
            Node next = previous.next;

            while (next != null)
            {
                if (previous.data.Equals(next.data))
                    previous.next = next.next;
                else
                    previous = previous.next;

                next = next.next;
            }
            next = head;
            while (next != null && previous != null)
            {
                if (previous.data.Equals(next.data))
                {
                    next = next.next;
                    previous = previous.next;
                }
            }
            head = next;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Lista encadeada \n");

            LinkedList list = new LinkedList();

            list.AddFirst("Fernandes");
            list.AddFirst("Gabriel");

            list.PrintAllNodes();// Gabriel Fernandes

            Console.WriteLine("\n \n");

            list.AddLast("Giraud");

            list.PrintAllNodes(); // Gabriel Fernandes Giraud

            object value = list.Find("Giraud");
            value = list.Find("Marijuana");

            list.AddFirst("Marijuana");
            list.PrintAllNodes();

            list.FindAndRemove("Marijuana");
            list.PrintAllNodes();

            LinkedList nomes = new LinkedList();
            nomes.AddList(list);

            nomes.PrintAllNodes();

            LinkedList numeros = new LinkedList();

            numeros.AddFirst(1);
            numeros.AddFirst(1);
            numeros.AddFirst(2);
            numeros.AddFirst(2);
            numeros.AddFirst(3);
            numeros.AddFirst(4);
            numeros.AddLast(5);
            numeros.AddLast(4);
            numeros.AddLast(4);
            numeros.AddLast(4);
            numeros.AddLast(4);
            numeros.AddLast(4);
            numeros.AddLast(4);
            numeros.AddLast(4);

            numeros.PrintAllNodes();

            numeros.Distinct();

            numeros.PrintAllNodes();
        }
    }
}
