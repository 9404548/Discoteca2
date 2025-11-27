using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Solicitar al usuario que introduzca la expresión en formato infijo
        Console.Write("Introduzca expresión infija: ");
        string infijo = Console.ReadLine();

        if (infijo == null)
        {
            // Mostrar error si la expresión inicial está vacía
            Console.WriteLine("La expresión no puede estar vacía!");
            return;
        }
        string postfijo = infijoAPostfijo(infijo);
        if (postfijo == null)
        {
            // Mostrar error si la conversión ha fallado
            Console.WriteLine("Expresión inválida");
            return;
        }

        // Mostrar la expresión en formato postfija.
        Console.WriteLine("Expresión postfija: " + postfijo);

        try
        {
            // Calcular el resultado numérico.
            double result = calcularResultado(postfijo);
            Console.WriteLine("Resultado: " + result);
        }
        catch (Exception ex)
        {
            // Si ocurre un error durante la evaluación, mostrar el mensaje de error
            Console.WriteLine("Error evaluando: " + ex.Message);
        }
    }

    static string infijoAPostfijo(string infijo)
    {
        // Pila para almacenar operadores temporalmente
        Stack<char> operadores = new Stack<char>();
        string postfijo = "";
        int i = 0;

        while (i < infijo.Length)
        {
            char c = infijo[i];
            if (char.IsWhiteSpace(c))
            {
                i++;
                continue;
            }
            if (char.IsLetter(c))
            {
                // Si es una letra (variable), lo metemos directamente a la cadena final
                postfijo += $"{c} ";
                i++;
            }
            else if (char.IsDigit(c))
            {
                string num = "";
                while (i < infijo.Length && char.IsDigit(infijo[i]))
                {
                    num += infijo[i];
                    i++;
                }
                postfijo += num + " ";
            }
            else if (c == '(')
            {
                // Si es paréntesis de apertura, lo apilamos
                operadores.Push(c);
                i++;
            }
            else if (c == ')')
            {
                // Si es un cierre de paréntesis, desapilamos los operadores hasta encontrar la apertura anterior
                while (operadores.Count > 0 && operadores.Peek() != '(') // .Peek() mira la siguiente posición
                {
                    postfijo += $"{operadores.Pop()} ";
                }
                if (operadores.Count == 0) // Devolvemos null si hay paréntesis desparejados
                    return null;

                operadores.Pop(); // Quitamos el '(' de la pila
                i++;
            }
            else if (IsOperator(c))
            {
                // Si es un operador, desapilamos los operadores de mayor o igual importancia
                int prec = Precedence(c);
                while (operadores.Count > 0 && Precedence(operadores.Peek()) >= prec)
                {
                    if (c == '^' && operadores.Peek() == '^') break;
                    postfijo += $"{operadores.Pop()} ";
                }
                // Apilamos el operador que acabamos de leer
                operadores.Push(c);
                i++;
            }
            else // Damos error si es un carácter inválido
            {
                return null;
            }
        }

        // Desapilamos cualquier operador restante
        while (operadores.Count > 0)
        {
            if (operadores.Peek() == '(') // Devolvemos null si hay paréntesis desparejados
                return null;
            postfijo += $"{operadores.Pop()} ";
        }

        return postfijo.Trim();
    }

    // Método auxiliar para verificar los operadores
    static bool IsOperator(char c)
    {
        return "+-*/^".Contains(c);
    }

    // Método que devuelve la precedencia de un operador
    static int Precedence(char c)
    {
        switch (c)
        {
            case '+':
            case '-':
                return 1; // Menor precedencia
            case '*':
            case '/':
                return 2;
            case '^':
                return 3; // Mayor precedencia
            default:
                return 0;
        }
    }

    static double calcularResultado(string postfijo)
    {
        Stack<double> stack = new Stack<double>();
        // Dividir la expresión postfija en tokens separados por espacios (es necesario el " + ' '" en la parte anterior para que funcione)
        string[] tokens = postfijo.Split(' ', StringSplitOptions.RemoveEmptyEntries);

        foreach (string token in tokens)
        {
            if (token.Length == 1 && char.IsLetter(token[0]))
            {
                // Si es una letra, calcular su valor como código ASCII menos 'Z'
                double val = (int)token[0] - (int)'Z';
                stack.Push(val);
            }
            else if (double.TryParse(token, out double num))
            {
                // Si es un numero, convertirla a número y apilarla
                stack.Push(num);
            }
            else if (IsOperator(token[0]))
            {
                // Si es un operador, desapilar dos operandos y aplicar la operación
                if (stack.Count < 2)
                    throw new Exception("Expresión postfija inválida");

                double b = stack.Pop();
                double a = stack.Pop();

                double res = 0;
                switch (token[0])
                {
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    case '/':
                        if (b == 0)
                            throw new Exception("División por cero"); // Devolvemos error si es una división por cero
                        res = a / b;
                        break;
                    case '^':
                        res = Math.Pow(a, b);
                        break;
                }
                // Apilamos el resultado
                stack.Push(res);
            }
            else
            {
                // Si el token es inválido, lanzamos una excepción
                throw new Exception("Token inválido: " + token);
            }
        }

        // Al final, la pila un único valor (el resultado)
        if (stack.Count != 1)
            throw new Exception("Expresión postfija inválida");
        return stack.Pop();
    }
}
