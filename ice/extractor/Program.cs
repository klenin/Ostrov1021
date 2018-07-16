using System;
using System.IO;
using System.IO.Compression;

namespace extractor
{
    class Program
    {
        static void ExtractZip(string path, string filename, string targetPath)
        {
            using (var archive = ZipFile.Open(filename, ZipArchiveMode.Read))
            {
                foreach (var file in archive.Entries)
                {
                    try
                    {
                        if (file.CompressedLength * 10 > file.Length)
                        {
                            var date = file.LastWriteTime;
                            file.ExtractToFile(targetPath + "/NOAA_" + $"{date.Year}{date.Month.ToString().PadLeft(2, '0')}{date.Day.ToString().PadLeft(2, '0')}_{date.Hour.ToString().PadLeft(2, '0')}{date.Minute.ToString().PadLeft(2, '0')}{date.Second.ToString().PadLeft(2, '0')}" + "__" + file.Name, true);
                        }
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e.ToString());
                    }
                }
            }
        }
        
        static void Go(string path)
        {
            var directories = Directory.EnumerateDirectories(path);
            foreach (var directory in directories)
            {
                Go(directory.ToString());
            }

            {
                var files = Directory.EnumerateFiles(path, "*.zip");
                foreach (var file in files)
                {
                    try
                    {
                        ExtractZip(path, file, "./extracted");
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e.ToString());
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Go(".");
        }
    }
}
