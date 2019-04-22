# PROJECT - Part 1

Part 1 work:

1. Created 3 tables in PostGreSQL, using script written in Notepad (in repo)
2. Wrote code to generate data (C++ code and generated data file in repo). The code generated a comma-delimited file.
3. Imported the data file into PostGreSQL (pgAdmin 4), using the Import tool.
4. Ran SELECT * queries to demonstrate that tables contain data. (Output shown limited to 10 lines)

System being used: PostGreSQL with pgAdmin 4
   Reason for choice: I used PostGreSQL a little bit in CS 586, but want to develop more skill in using it as a tool.
                      Low overhead, ability to install on external drive (required for use on my laptop).

Issues encountered: I first wrote the C++ code to generate a space-delimited file, which I uploaded into Excel. However,
                    when I tried to save that as a .csv (comma-delimited file), the output did not contain commas & could
                    not be imported directly into pgAmin 4. Therefore, I changed my C++ code to create the comma-delimited
                    output directly. That is easily imported into pgAdmin 4.
Lessons learned: I hadn't used the import tool in pgAdmin 4 before. It works quite well for comma delimited files generated
                 from the C++ code.
