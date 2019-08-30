using System;
using System.Collections.Generic;
using System.Text;

namespace CreatingXMLDocument
{
    public class BookStore
    {
        public BookCategory Category { get; set; }
        public string Title { get; set; }
        public List<Author> Author { get; set; }
        public int Year { get; set; }
        public double Price { get; set; }

        public string Lang { get; set; }
        public List<BookStore> GetBookStores()
        {
            var list = new List<BookStore>()
            {
                new BookStore
                {
                    Category = BookCategory.COOKING,
                    Title = "Everyday Italian",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "Giada De Laurentiis"}
                    },
                    Year = 2005,
                    Price = 30.00,
                    Lang = "en"
                },
                new BookStore
                {
                    Category = BookCategory.COOKING,
                    Title = "The Joy of Cooking",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "Irma S. Rombauer"}
                    },
                    Year = 1931,
                    Price = 20.78,
                    Lang = "en"
                },
                new BookStore
                {
                    Category = BookCategory.COOKING,
                    Title = "Everyday Italian",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "Giada De Laurentiis"}
                    },
                    Year = 2005,
                    Price = 30.00,
                    Lang = "en"
                },
                new BookStore
                {
                    Category = BookCategory.CHILDREN,
                    Title = "Harry Potter",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "J K. Rowling"}
                    },
                    Year = 2005,
                    Price = 29.99,
                    Lang = "en"
                },new BookStore
                {
                    Category = BookCategory.WEB,
                    Title = "XQuery Kick Start",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "James McGovern"},
                        new Author{ Name = "Per Bothner"},
                        new Author{ Name = "Kurt Cagle"},
                        new Author{ Name = "James Linn"},
                        new Author{ Name = "Vaidyanathan Nagarajan"},
                    },
                    Year = 2003,
                    Price = 49.99,
                    Lang = "en"
                }
                ,new BookStore
                {
                    Category = BookCategory.WEB,
                    Title = "Learning XML",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "Erik T. Ray"}
                    },
                    Year = 2003,
                    Price = 39.95,
                    Lang = "en"
                }
                ,new BookStore
                {
                    Category = BookCategory.WEB,
                    Title = "Database System Concepts",
                    Author = new List<Author>()
                    {
                        new Author{ Name = "Avi Silberschatz"},
                        new Author{ Name = "Henry F. Korth"},
                        new Author{ Name = "S. Sudarshan"},

                    },
                    Year = 1986,
                    Price = 95.55,
                    Lang = "en"
                }

            };

            return list;
        }
    }
    public enum BookCategory
    {
        COOKING,
        CHILDREN,
        WEB
    }
    public class Author
    {
        public string Name { get; set; }
    }
}
