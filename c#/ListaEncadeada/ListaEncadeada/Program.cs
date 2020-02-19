
using System;
using System.Collections.Generic;

namespace ListaEncadeada
{
    public class Celula<T>
    {
        public T Valor { get; set; } = default;
        public Celula<T> Proximo { get; set; } = new Celula<T>();
    }

    public class Lista<T>
    {
        public Lista()
        {
            Tam = 0;
            primeiro = new Celula<T>();
            primeiro.Valor = default;
            primeiro.Proximo = null;
            ultimo = primeiro;
        }

        public int Tam { get; private set; }

        private Celula<T> primeiro;
        private Celula<T> ultimo;
        private Celula<T> aux;


        public bool IsVazia()
        {
            return (ultimo == primeiro);
        }
        public void InserirUltimo(T valor)
        {
            ultimo = new Celula<T>();
            ultimo.Proximo.Valor = valor;
            ultimo = ultimo.Proximo;
            Tam++;
        }

        public void InserirPrimeiro(T valor)
        {
            Celula<T> nova = new Celula<T>();
            nova.Valor = valor;
            nova.Proximo = primeiro.Proximo;
            if (IsVazia())
                ultimo = primeiro.Proximo;
            primeiro.Proximo = primeiro;
            primeiro = nova;
            Tam++;
        }

        public void ListarTudo()
        {
            aux = primeiro.Proximo;
            while (aux != null)
            {
                Console.WriteLine(aux.Valor);
                aux = aux.Proximo;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Lista<int> lst = new Lista<int>();
            lst.InserirPrimeiro(1);
            lst.InserirPrimeiro(2);
            lst.InserirUltimo(3);
            Console.WriteLine(lst.Tam);
        }
    }
}
