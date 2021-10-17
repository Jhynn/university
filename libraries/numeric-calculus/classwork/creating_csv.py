import csv
# ################# Escrevendo um arquivo .csv ###################
# Nomes dos campos.
fields = ['Ano', 'Brasil', 'UF', 'Capital+RM', 'Interior']

# linhas do .csv
rows = [
    ['1980', '11.7', '2.4', '6.8', '0.8'],
    ['1981', '12.6', '3.6', '9.2', '1.5'],
    ['1982', '12.6', '5.4', '10.1', '3.5'],
    ['1983', '13.8', '6.0', '11.5', '3.8'],
    ['1984', '15.3', '4.4', '9.7', '2.1'],
    ['1985', '15.0', '3.4', '6.6', '2.0'],
    ['1986', '15.3', '4.5', '8.0', '2.9'],
    ['1987', '16.9', '3.4', '6.5', '2.0'],
    ['1988', '16.8', '5.8', '12.7', '2.7'],
    ['1989', '20.3', '5.9', '13.9', '2.1'],
    ['1990', '22.2', '4.5', '12.0', '0.9'],
    ['1991', '20.8', '4.4', '11.8', '0.7'],
    ['1992', '19.1', '3.7', '8.8', '1.1'],
    ['1993', '20.2', '4.6', '9.0', '2.3'],
    ['1994', '21.2', '3.8', '8.0', '1.7'],
    ['1995', '23.8', '4.4', '10.8', '1.2'],
    ['1996', '24.8', '4.7', '12.0', '0.9'],
    ['1997', '25.4', '5.7', '12.8', '1.8'],
    ['1998', '25.9', '5.2', '13.7', '0.6'],
    ['1999', '26.2', '4.8', '11.3', '1.2'],
    ['2000', '26.7', '8.2', '18.2', '1.7'],
    ['2001', '27.8', '9.7', '18.0', '4.8'],
    ['2002', '28.5', '10.9', '21.5', '4.5'],
    ['2003', '28.9', '10.8', '22.1', '4.0'],
    ['2004', '27.0', '11.8', '20.6', '6.5'],
    ['2005', '25.8', '12.8', '23.9', '5.8'],
    ['2006', '26.3', '14.4', '27.5', '5.9'],
    ['2007', '25.2', '13.2', '23.2', '6.7'],
    ['2008', '26.4', '12.4', '22.2', '6.0'],
    ['2009', '27.0', '12.8', '22.1', '6.7'],
    ['2010', '26.2', '13.7', '24.8', '6.4']
]

# Nome do .csv
file_name = "violencia_pi.csv"

# Escrevendo no .csv
with open(file_name, 'w') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(fields)  # Escrevendo os campos.
    csv_writer.writerows(rows)   # Escrevendo as, outras, informações.

# ################# Lendo um .csv ################################

# Nome do arquivo .csv
file_name = "violencia_pi.csv"

fields, rows = list(), list()

with open(file_name, 'r') as csvfile:
    csv_reader = csv.reader(csvfile)
    fields = csv_reader.__next__()  # Obtendo os nomes dos campos, na 1ª linha.

    for row in csv_reader:
        rows.append(row)  # Obtendo cada linha.

    print("%d linha(s).\n" % (csv_reader.line_num))  # Número total de linhas.

print("Violência no Piauí.")
print('Campos: ' + ', '.join(field for field in fields) + '.')

for row in rows:
    for element in row:
        print("%s" % (element), end='\t')
    print('\n')
