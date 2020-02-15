-- 1) CREARE la base di dati e le rispettive tabelle avendo cura di definirne i vincoli
CREATE SCHEMA immobili;

USE immobili;

CREATE TABLE immobile(
    cod INT PRIMARY KEY,
    tipo VARCHAR(12),
    indirizzo VARCHAR(40),
    citta VARCHAR(40)
);

CREATE TABLE anagrafica_cittadino(
    codfiscale char(16) PRIMARY KEY,
    nome VARCHAR(25),
    cogn VARCHAR(25),
    datanascita DATE,
    indirizzoresidenza VARCHAR(40),
    citta VARCHAR(40)
);

CREATE TABLE immobile_proprietario(
    codfiscale char(16) REFERENCES anagrafica_cittadino(codfiscale),
    codimmobile INT REFERENCES immobile(cod),

    PRIMARY KEY(codfiscale, codimmobile)
);

-- 2) POPOLARE la base di dati con un numero significativo (es. 4) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo cittadino con un certo numero di immobili)
INSERT INTO immobile VALUES(0, "Casa d'epoca", "Viale Magna Grecia 2", "Taranto");
INSERT INTO immobile VALUES(1, "Appartamento", "Corso Italia 5", "Bari");
INSERT INTO immobile VALUES(2, "Villa", "Via Cesare Battisti 72", "Taranto");
INSERT INTO immobile VALUES(3, "Appartamento", "Via Galeso 15", "Taranto");
INSERT INTO immobile VALUES(4, "Villa", "Via Orsini 52", "Milano");

INSERT INTO anagrafica_cittadino VALUES("SSSVCN99E15R789H", "Vincenzo", "Susso", "1999-11-15", "Via Galeso 15", "Taranto");
INSERT INTO anagrafica_cittadino VALUES("PPPPLT80R24Q741Y", "Pippo", "Pluto", "1980-07-24", "Via Pippo Pluto 25", "Milano");
INSERT INTO anagrafica_cittadino VALUES("RBRDNR75Q10R963V", "Robert", "De Niro", "1975-02-10", "Via Cesare Battisti 72", "Taranto");
INSERT INTO anagrafica_cittadino VALUES("GNNSPS60W25V123U", "Gennaro", "Esposito", "1960-04-25", "Via Orsini 52", "Milano");
INSERT INTO anagrafica_cittadino VALUES("MRARSS90P04L321P", "Maria", "Rossi", "1990-10-04", "Viale Magna Grecia 2", "Taranto");

INSERT INTO immobile_proprietario VALUES("MRARSS90P04L321P", 0);
INSERT INTO immobile_proprietario VALUES("SSSVCN99E15R789H", 1);
INSERT INTO immobile_proprietario VALUES("RBRDNR75Q10R963V", 2);
INSERT INTO immobile_proprietario VALUES("RBRDNR75Q10R963V", 3);
INSERT INTO immobile_proprietario VALUES("GNNSPS60W25V123U", 4);

-- 3) Scrivere le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Trovare: Nome, Cognome e Codice Fiscale di tutti coloro i quali sono proprietari di un immobile ma in una città diversa da quella di residenza, ovvero non possiedono alcuna casa nella città di residenza
SELECT DISTINCT ac.nome, ac.cogn, ac.codfiscale FROM anagrafica_cittadino ac JOIN immobile_proprietario ip ON ac.codfiscale = ip.codfiscale JOIN immobile i ON ip.codimmobile = i.cod WHERE ac.citta <> i.citta;

-- 3.2) Trovare: Nome, Cognome e Codice Fiscale dei cittadini che risiedono in un appartamento pur essendo proprietari, nella stessa città di residenza, di una villa 
SELECT DISTINCT ac.nome, ac.cogn, ac.codfiscale FROM anagrafica_cittadino ac JOIN immobile_proprietario ip ON ac.codfiscale = ip.codfiscale JOIN immobile i ON ip.codimmobile = i.cod WHERE ac.citta = i.citta AND i.tipo = "Appartamento" AND ac.codfiscale IN (SELECT i_p.codfiscale FROM immobile im JOIN immobile_proprietario i_p ON im.cod= i_p.codimmobile WHERE im.tipo = "Villa" AND i.citta = im.citta);

-- 3.3) Trovare: Nome, Cognome e Codice Fiscale dei cittadini residenti a Milano e che non possiedono alcun immobile
SELECT DISTINCT ac.nome, ac.cogn, ac.codfiscale FROM anagrafica_cittadino ac WHERE ac.citta = "Milano" AND ac.codfiscale NOT IN (SELECT DISTINCT codFiscale FROM immobile_proprietario); 

-- 4) MODIFICARE la base di dati per rappresentare che un cittadino possa essere proprietario di al più un immobile
DROP TABLE immobile_proprietario;

ALTER TABLE anagrafica_cittadino ADD COLUMN immobile INT REFERENCES immobile(cod);

UPDATE anagrafica_cittadino SET immobile = 0 WHERE codfiscale = "SSSVCN99E15R789H";
UPDATE anagrafica_cittadino SET immobile = 1 WHERE codfiscale = "PPPPLT80R24Q741Y";
UPDATE anagrafica_cittadino SET immobile = 2 WHERE codfiscale = "RBRDNR75Q10R963V";
UPDATE anagrafica_cittadino SET immobile = 3 WHERE codfiscale = "GNNSPS60W25V123U";
UPDATE anagrafica_cittadino SET immobile = 4 WHERE codfiscale = "MRARSS90P04L321P";