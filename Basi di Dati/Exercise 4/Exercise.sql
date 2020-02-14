-- 1) CREARE la base di dati e le rispettive tabelle avendo curi di definirne chiave e vincoli
CREATE SCHEMA banca;

use banca;

CREATE TABLE correntisti(
    cf CHAR(16) PRIMARY KEY,
    cogn VARCHAR(30),
    nome VARCHAR(30),
    datanascita DATE,
    tipocontratto VARCHAR(18),
    cittaresidenza VARCHAR(30)
);

CREATE TABLE dipendente(
    cf CHAR(16) PRIMARY KEY,
    nome VARCHAR(30),
    cogn VARCHAR(30),
    datanasc DATE,
    qualifica VARCHAR(9)
);

CREATE TABLE conto_corrente(
    numcc INT PRIMARY KEY,
    cf_correntista CHAR(16) REFERENCES correntisti(cf),
    saldo DECIMAL(10,2)
);

-- 2) POPOLARE la base di dati con un numero significativo (es 4,5) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo correntista)
INSERT INTO correntisti VALUES("SSSVCN99S15P54G", "Susso", "Vincenzo", "1999-11-15", "TempoIndeterminato", "Taranto");
INSERT INTO correntisti VALUES("SPSGNN70G02P78S", "Esposito", "Gennaro", "1970-10-02", "TempoDeterminato", "Napoli");
INSERT INTO correntisti VALUES("PPPPLT85V10R78X", "Pippo", "Pluto", "1985-03-10", "TempoIndeterminato", "Taranto");
INSERT INTO correntisti VALUES("DNRRBR52T27Q99F", "De Niro", "Robert", "1952-06-27", "TempoDeterminato", "Milano");
INSERT INTO correntisti VALUES("MNTTNY22J30E12K", "Montana", "Tony", "1960-07-22", "TempoIndeterminato", "Milano");
INSERT INTO correntisti VALUES("BNCLCA89O11L74R", "Bianchi", "Lucia", "1989-02-13", "TempoIndeterminato", "Genova");


INSERT INTO dipendente VALUES("SPSGNN70G02P78S", "Gennaro", "Esposito", "1970-10-02", "Dirigente");
INSERT INTO dipendente VALUES("DNRRBR52T27Q99F", "Robert", "De Niro", "1952-06-27", "Impiegato");
INSERT INTO dipendente VALUES("PPPPLT85V10R78X", "Pluto", "Pippo", "1985-03-10", "Quadro");
INSERT INTO dipendente VALUES("LCABRS62G27G11L", "Luca", "Brasi", "1962-10-27", "Impiegato");
INSERT INTO dipendente VALUES("MRARSS97N14Z19K", "Maria", "Rossi", "1997-04-14", "Dirigente");

INSERT INTO conto_corrente VALUES(0, "SSSVCN99S15P54G", 200250);
INSERT INTO conto_corrente VALUES(1, "SSSVCN99S15P54G", 900150);
INSERT INTO conto_corrente VALUES(2, "SPSGNN70G02P78S", 150000.15);
INSERT INTO conto_corrente VALUES(3, "PPPPLT85V10R78X", 35000);
INSERT INTO conto_corrente VALUES(4, "PPPPLT85V10R78X", 1800.34);
INSERT INTO conto_corrente VALUES(5, "MNTTNY22J30E12K", 20000.79);
INSERT INTO conto_corrente VALUES(6, "BNCLCA89O11L74R", 60000.99);

-- 3) FORMULARE le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Trovare: nome, cognome e codice fiscale dei correntisti che hanno un lavoro a tempo determinato ed un saldo superiore a 100 mila euro. Mostrare i risultati rispetto alla città di residenza
SELECT DISTINCT c.nome, c.cogn, c.cf FROM correntisti c JOIN conto_corrente cc ON c.cf = cc.cf_correntista WHERE c.tipocontratto LIKE "TempoDeterminato" AND cc.saldo > 100000 GROUP BY c.cittaresidenza;

-- 3.2) Trovare: nome, cognome e codice fiscale dei dipendenti con un contratto a tempo indeterminato che hanno più di un contro corrente. Per ognuno mostrare i numeri di conto corrente posseduto
SELECT c.nome, c.cogn, c.cf FROM correntisti c JOIN dipendente d ON c.cf = d.cf JOIN conto_corrente cc ON d.cf = cc.cf_correntista WHERE c.tipocontratto LIKE "TempoIndeterminato" GROUP BY cc.cf_correntista HAVING count(cc.numcc) > 1;

-- 3.3) Trovare: nome, cognome e codice fiscale dei dipendenti con qualifica di dirigente che non possiedono alcun conto corrente presso la banca
SELECT d.nome, d.cogn, d.cf FROM dipendente d WHERE d.qualifica LIKE "Dirigente" and d.cf NOT IN (SELECT cf_correntista FROM conto_corrente);

-- 4) MODIFICARE la base di dati per:

-- 4.1) Consentire di avere traccia delle filiali della banca ed il relativo direttore (che è un dipendente con qualunque qualifica)
CREATE TABLE filiale(
    codice INT PRIMARY KEY,
    direttore CHAR(16) REFERENCES dipendente(cf),
    indirizzo VARCHAR(40)
);

INSERT INTO filiale VALUES(0, "SPSGNN70G02P78S", "Via Cesare Battisti 2");
INSERT INTO filiale VALUES(1, "MRARSS97N14Z19K", "Viale Magna Grecia 78");
INSERT INTO filiale VALUES(2, "LCABRS62G27G11L", "Corso Italia 15");

-- 4.2) Tenere traccia della filiale presso la quale è stato aperto un conto corrente (N.B: un conto corrente può essere aperto presso una sola filiale)
ALTER TABLE conto_corrente ADD filiale INT REFERENCES filiale(codice);

UPDATE conto_corrente SET filiale = 0 WHERE numcc = 0;
UPDATE conto_corrente SET filiale = 1 WHERE numcc = 1;
UPDATE conto_corrente SET filiale = 2 WHERE numcc = 2;
UPDATE conto_corrente SET filiale = 2 WHERE numcc = 3;
UPDATE conto_corrente SET filiale = 1 WHERE numcc = 4;
UPDATE conto_corrente SET filiale = 1 WHERE numcc = 5;
UPDATE conto_corrente SET filiale = 0 WHERE numcc = 6;