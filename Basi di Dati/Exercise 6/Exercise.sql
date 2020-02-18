-- 1) CREARE la base di dati e le rispettive tabelle avendo cura di definirne i vincoli
CREATE SCHEMA auto_moto;

USE auto_moto;

CREATE TABLE auto(
	targa CHAR(7) PRIMARY KEY,
	tipo VARCHAR(10) NOT NULL,

	CHECK(tipo LIKE "Sportiva" OR tipo LIKE "Berlina" OR tipo LIKE "Utilitaria")
);

CREATE TABLE moto(
	targa CHAR(7) PRIMARY KEY,
	tipo VARCHAR(11) NOT NULL

	CHECK(tipo LIKE "Custom" OR tipo LIKE "CafeRacer" OR tipo LIKE "GranTurismo")
);

CREATE TABLE proprietario(
	codfiscale CHAR(16) PRIMARY KEY,
	nome VARCHAR(30) NOT NULL,
	cognome VARCHAR(30) NOT NULL,
	cittaresidenza VARCHAR(40)
);

CREATE TABLE auto_proprietario(
	targa CHAR(7) REFERENCES auto(targa),
	codfiscale CHAR(16) REFERENCES proprietario(codfiscale),

	PRIMARY KEY(targa, codfiscale)
);

CREATE TABLE moto_proprietario(
	targa CHAR(7) REFERENCES moto(targa),
	codfiscale CHAR(16) REFERENCES proprietario(codfiscale),

	PRIMARY KEY(targa, codfiscale)
);

-- 2) POPOLARE la base di dati con un numero significativo (es. 3/4) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo libro)
INSERT INTO auto VALUES("AA123AA", "Sportiva");
INSERT INTO auto VALUES("AC985DA", "Berlina");
INSERT INTO auto VALUES("CJ893XB", "Utilitaria");
INSERT INTO auto VALUES("DF753PC", "Sportiva");
INSERT INTO auto VALUES("PE852CA", "Berlina");

INSERT INTO moto VALUES("FG159TA", "Custom");
INSERT INTO moto VALUES("TT555TT", "Custom");
INSERT INTO moto VALUES("PO741OP", "GranTurismo");
INSERT INTO moto VALUES("GE552QW", "CafeRacer");

INSERT INTO proprietario VALUES("SSSVCN99R15Q85L", "Vincenzo", "Susso", "Bari");
INSERT INTO proprietario VALUES("PPPPLT52Q02O98Z", "Pippo", "Pluto", "Bari");
INSERT INTO proprietario VALUES("MRARSS91Y25R41V", "Maria", "Rossi", "Bari");
INSERT INTO proprietario VALUES("GNNSPS85U14Q01Q", "Gennaro", "Esposito", "Taranto");

INSERT INTO auto_proprietario VALUES("AA123AA", "PPPPLT52Q02O98Z");
INSERT INTO auto_proprietario VALUES("AC985DA", "PPPPLT52Q02O98Z");
INSERT INTO auto_proprietario VALUES("CJ893XB", "MRARSS91Y25R41V");
INSERT INTO auto_proprietario VALUES("DF753PC", "MRARSS91Y25R41V");
INSERT INTO auto_proprietario VALUES("PE852CA", "GNNSPS85U14Q01Q");

INSERT INTO moto_proprietario VALUES("FG159TA", "SSSVCN99R15Q85L");
INSERT INTO moto_proprietario VALUES("TT555TT", "MRARSS91Y25R41V");
INSERT INTO moto_proprietario VALUES("PO741OP", "GNNSPS85U14Q01Q");
INSERT INTO moto_proprietario VALUES("GE552QW", "MRARSS91Y25R41V");

-- 3) scrivere le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Trovare: Nome, Cognome, Cod.Fiscale e cittò di coloro i quali posseggono una moto custom ma non posseggono alcuna auto
SELECT p.nome, p.cognome, p.codfiscale FROM proprietario p JOIN moto_proprietario mp ON p.codfiscale = mp.codfiscale JOIN moto m ON mp.targa = m.targa WHERE m.tipo LIKE "Custom" AND p.codfiscale NOT IN (SELECT codfiscale FROM auto_proprietario);

-- 3.2) Trovare: Nome, Cognome, Cod.Fiscale di coloro i quali risiedono a Bari e sono proprietari sia di una moto custom che di una moto cafe racer
SELECT p.nome, p.cognome, p.codfiscale FROM proprietario p JOIN moto_proprietario mp ON p.codfiscale = mp.codfiscale JOIN moto m ON mp.targa = m.targa WHERE m.tipo LIKE "Custom" AND p.cittaresidenza LIKE "Bari" AND p.codfiscale IN (SELECT p.codfiscale FROM proprietario p JOIN moto_proprietario mp ON p.codfiscale = mp.codfiscale JOIN moto m ON mp.targa = m.targa WHERE m.tipo LIKE "CafeRacer" AND p.cittaresidenza LIKE "Bari");

-- 3.3) Trovare: Nome, Cognome, Cod.Fiscale di coloro i quali risiedono a Bari e posseggono più di una moto
SELECT p.nome, p.cognome, p.codfiscale FROM proprietario p JOIN moto_proprietario mp ON p.codfiscale = mp.codfiscale JOIN moto m ON mp.targa = m.targa WHERE p.cittaresidenza LIKE "Bari" GROUP BY mp.codfiscale HAVING count(mp.targa) > 1;

-- 4) MODIFICARE la base di dati per gestire il fatto che una persona possieda al più una moto
ALTER TABLE proprietario ADD COLUMN moto CHAR(7) REFERENCES moto(targa);

UPDATE proprietario p JOIN moto_proprietario mp ON p.codfiscale = mp.codfiscale SET p.moto = mp.targa;   

DROP TABLE moto_proprietario;