using System.Text;

namespace Baekjoon_18258
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();

            Queue<int> queue = new Queue<int>();

            int N = int.Parse(Console.ReadLine());
            int back = 0;
            for (int i = 0; i < N; i++)
            {
                string[] input = Console.ReadLine().Split();
                string fun = input[0];
                switch (fun)
                {
                    case "push":
                        int value = int.Parse(input[1]);
                        back = value;
                        queue.Enqueue(value);
                        break;

                    case "pop":
                        if (queue.Count == 0)
                        {
                            sb.AppendLine("-1");
                        }
                        else
                        {
                            sb.AppendLine(queue.Dequeue().ToString());

                        }
                        break;
                    case "size":
                        sb.AppendLine(queue.Count + "");
                        break;
                    case "empty":
                        if (queue.Count == 0)
                        {
                            sb.AppendLine("1");
                        }
                        else
                        {
                            sb.AppendLine("0");
                        }
                        break;

                    case "front":
                        if (queue.Count == 0)
                        {
                            sb.AppendLine("-1");
                        }
                        else
                        {
                            sb.AppendLine(queue.Peek().ToString());
                        }
                        break;

                    case "back":
                        if (queue.Count == 0)
                        {
                            sb.AppendLine("-1");
                        }
                        else
                        {
                            sb.AppendLine(back.ToString());
                        }

                        break;
                }
            }
            Console.Write(sb.ToString());
        }
    }
}