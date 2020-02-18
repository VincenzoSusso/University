-- 1) CREARE la base di dati e le rispettive tabelle avendo cura di definirne i vincoli
CREATE SCHEMA banca;

USE banca;

CREATE TABLE correntisti(
	cf CHAR(16) PRIMARY KEY,
	cogn VARCHAR(30) NOT NULL,
	nome VARCHAR(30) NOT NULL,
	datanascita DATE NOT NULL
);

CREATE TABLE dipendente(
	cf CHAR(16) PRIMARY KEY,
	nome VARCHAR(30) NOT NULL,
	cogn VARCHAR(30) NOT NULL,
	datanasc DATE NOT NULL,
	filiale INT REFERENCES filiale(cod),
	qualifica VARCHAR(10) NOT NULL,

	CHECK(qualifica LIKE "Impiegato" OR qualifica LIKE "Quadro" OR qualifica LIKE "Dirigente")
);

CREATE TABLE filiale(
	cod INT PRIMARY KEY,
	nomefiliale VARCHAR(30) NOT NULL,
	citta VARCHAR(40) NOT NULL,
	cf_direttore CHAR(16) REFERENCES dipendente(cf)
);

CREATE TABLE conto_corrente(
	numcc INT PRIMARY KEY,
	codfiliale INT REFERENCES filiale(cod)
);

CREATE TABLE titolare_cc(
	numcc INT REFERENCES conto_corrente(numcc),
	cf_titolare CHAR(16) REFERENCES correntisti(cf),

	PRIMARY KEY (numcc, cf_titolare)
);

-- 2) POPOLARE la base di dati con un numero significativo (es. 4,5) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo correntista)
INSERT INTO correntisti VALUES("SSSVCN99G15P743V", "Susso", "Vincenzo", "1999-11-15");
INSERT INTO correntisti VALUES("RSSMRA50T25K123Q", "Rossi", "Maria", "1950-12-25");
INSERT INTO correntisti VALUES("BNCGVN85P10Q159W", "Bianchi", "Giovanni", "1985-01-10");
INSERT INTO correntisti VALUES("SPSMRO74L14T147U", "Esposito", "Mario", "1974-06-14");
INSERT INTO correntisti VALUES("VLASSN79Q20B148N", "Viola", "Alessandra", "1979-09-20");
INSERT INTO correntisti VALUES("PLTPPP97V15C486B", "Pippo", "Pluto", "1997-10-15");

INSERT INTO dipendente VALUES("SSSVCN99G15P743V", "Vincenzo", "Susso", "1999-11-15", 0, "Impiegato");
INSERT INTO dipendente VALUES("VRDGST65Q24A456C", "Agostino", "Verdi", "1965-05-24", 1, "Dirigente");
INSERT INTO dipendente VALUES("BRSLCA79X10B789L", "Luca", "Brasi", "1979-08-10", 2, "Quadro");
INSERT INTO dipendente VALUES("PLTPPP97V15C486B", "Pippo", "Pluto", "1997-10-15", 0, "Impiegato");
INSERT INTO dipendente VALUES("TPLPPR89C19A426N", "Paperino", "Topolino", "1989-09-19", 2, "Dirigente");
INSERT INTO dipendente VALUES("LCAGRG65A06R565B", "Grigio", "Lucia", "1965-02-06", 2, "Dirigente");

INSERT INTO filiale VALUES(0, "Rosso", "Bari", "PLTPPP97V15C486B");
INSERT INTO filiale VALUES(1, "Blu", "Taranto", "VRDGST65Q24A456C");
INSERT INTO filiale VALUES(2, "Verde", "Bari", "LCAGRG95A06R565B");

INSERT INTO conto_corrente VALUES(0, 0);
INSERT INTO conto_corrente VALUES(1, 0);
INSERT INTO conto_corrente VALUES(2, 1);
INSERT INTO conto_corrente VALUES(3, 2);
INSERT INTO conto_corrente VALUES(4, 2);
INSERT INTO conto_corrente VALUES(5, 1);

INSERT INTO titolare_cc VALUES(0, "SSSVCN99G15P743V");
INSERT INTO titolare_cc VALUES(0, "RSSMRA50T25K123Q");
INSERT INTO titolare_cc VALUES(1, "RSSMRA50T25K123Q");
INSERT INTO titolare_cc VALUES(1, "VLASSN79Q20B148N");
INSERT INTO titolare_cc VALUES(2, "SPSMRO74L14T147U");
INSERT INTO titolare_cc VALUES(3, "BNCGVN85P10Q159W");
INSERT INTO titolare_cc VALUES(4, "VLASSN79Q20B148N");
INSERT INTO titolare_cc VALUES(5, "PLTPPP97V15C486B");

-- 3) scrivere le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Trovare i conti correnti cointestati (aventi più di un correntista come titolare). Per ognuno di essi mostrare: il numero di conto, il nome della filiale in cui è stato aperto ed il nome e cognome dei titolari del conto
SELECT DISTINCT cc.numcc, f.nomefiliale, c.nome, c.cogn FROM titolare_cc tc JOIN conto_corrente cc ON tc.numcc = cc.numcc JOIN filiale f ON cc.codfiliale = f.cod JOIN correntisti c ON tc.cf_titolare = c.cf WHERE tc.numcc IN (SELECT DISTINCT numcc FROM titolare_cc GROUP BY numcc HAVING count(cf_titolare) > 1);  

-- 3.2) Trovare il nome e cognome dei dirigenti che non hanno alcun conto corrente in nessuna filiale della banca
SELECT DISTINCT d.nome, d.cogn FROM filiale f JOIN dipendente d ON f.cf_direttore = d.cf WHERE f.cf_direttore NOT IN (SELECT DISTINCT tc.cf_titolare FROM titolare_cc tc); 

-- 3.3) Trovare il nome di tutte le filiali che hano sede a bari e che hanno un direttore nato dopo il 01/01/1970. Mostrare quindi il nome, il cognome e la data di nascita del direttore.
SELECT f.nomefiliale, d.nome, d.cogn FROM filiale f JOIN dipendente d ON f.cf_direttore = d.cf WHERE f.citta LIKE "Bari" AND d.datanasc >= "1970-01-01";

-- 4) MODIFICARE la base di dati per consentire SOLO la gestione di conti correnti con un unico intestatario
ALTER TABLE conto_corrente ADD COLUMN cf_titolare CHAR(16) REFERENCES correntisti(cf);

UPDATE conto_corrente cc JOIN titolare_cc tc ON cc.numcc = tc.numcc SET cc.cf_titolare = tc.cf_titolare;

DROP TABLE titolare_cc;