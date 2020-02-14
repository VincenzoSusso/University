-- 1) CREARE la base di dati e le rispettive tabelle avendo cura di definire chiavi e vincoli
CREATE SCHEMA progetti;

USE progetti;

CREATE TABLE impiegato(
    matricola INT PRIMARY KEY,
    nome VARCHAR(25),
    cognome VARCHAR(25),
    datanascita DATE,
    stipendio DECIMAL(7,2)
);

CREATE TABLE progetto(
    codprogetto INT PRIMARY KEY,
    nome VARCHAR(25),
    datainizio DATE,
    datafine DATE,
    budget DECIMAL(9,2),
    responsabile INT REFERENCES impiegato(matricola)
);

CREATE TABLE coinvolgimento(
    matrimpiegato INT REFERENCES impiegato(matricola),
    codprogetto INT REFERENCES progetto(codprogetto),
    
    PRIMARY KEY (matrimpiegato, codprogetto)
);

CREATE TABLE divisione(
    coddivisione INT PRIMARY KEY,
    nome VARCHAR(25),
    budgetdivisione DECIMAL(9,2),
    direttore INT REFERENCES impiegato(matricola)
);

CREATE TABLE affiliazione(
    matricola INT REFERENCES impiegato(matricola),
    codicedivisione INT REFERENCES divisione(coddivisione),
    percentualetempo SMALLINT,
    
    PRIMARY KEY (matricola, codicedivisione),
    CHECK (percentualetempo >= 0 AND percentualetempo <= 100)
);

-- 2) POPOLARE la base di dati con un numero significativo (es .4) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo progetto)
INSERT INTO impiegato VALUES(0, "Vincenzo", "Susso", "1999-11-15", 60000);
INSERT INTO impiegato VALUES(1, "Pippo", "Pluto", "1985-04-19", 45000);
INSERT INTO impiegato VALUES(2, "Paperino", "Topolino", "1985-07-26", 55000);
INSERT INTO impiegato VALUES(3, "Gennaro", "Esposito", "1970-10-01", 30000);
INSERT INTO impiegato VALUES(4, "Federica", "Pellegrini", "1973-06-05", 51000);

INSERT INTO progetto VALUES(0, "Manhattan", "2002-01-01", "2080-09-01", 65000, 0);
INSERT INTO progetto VALUES(1, "Ferrari", "1970-06-05", "1972-06-05", 60000, 2);
INSERT INTO progetto VALUES(2, "Nintendo", "1999-10-25", "2002-01-15", 55000, 3);
INSERT INTO progetto VALUES(3, "Sony", "2001-07-10", "2008-04-10", 30000, 3);

INSERT INTO coinvolgimento VALUES(1, 1);
INSERT INTO coinvolgimento VALUES(2, 0);
INSERT INTO coinvolgimento VALUES(2, 3);
INSERT INTO coinvolgimento VALUES(4, 2);
INSERT INTO coinvolgimento VALUES(4, 3);
INSERT INTO coinvolgimento VALUES(4, 0);

INSERT INTO divisione VALUES(0, "Marketing", 150000, 3);
INSERT INTO divisione VALUES(1, "IT", 290000, 0);
INSERT INTO divisione VALUES(2, "Ufficio Pubbliche Relazioni", 100000, 4);

INSERT INTO affiliazione VALUES(0, 1, 45);
INSERT INTO affiliazione VALUES(1, 0, 25);
INSERT INTO affiliazione VALUES(2, 2, 5);
INSERT INTO affiliazione VALUES(3, 1, 35);
INSERT INTO affiliazione VALUES(4, 0, 10);

-- 3) Scrivere le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Trovare: nome, cognome e stipendio dei responsabili di progetti non ancora conclusi ed aventi un budget inferiore a 70 mila euro. Di tali progetti mostrare: il nome, il relativo budget, l'elenco(nome e cognome) degli impiegati che lavorano al progetto ed hanno uno stipendio di almeno 50 mila euro
SELECT i.nome AS nomeResponsabile, i.cognome AS cognomeResponsabile, i.stipendio AS stipendioResponsabile, p.nome AS nomeProgetto, p.budget AS budgetProgetto, im.nome AS nomeImpiegato, im.cognome AS cognomeImpiegato FROM progetto p JOIN impiegato i ON p.responsabile = i.matricola JOIN coinvolgimento c ON p.responsabile = c.codprogetto JOIN impiegato im ON c.matrimpiegato = im.matricola WHERE CURDATE() <= p.datafine AND im.stipendio >= 50000;

-- 3.2) Trovare: nome, cognome e stipendio degli impiegati che ricoprono solo il ruolo di responsabile di progetto e non sono coinvolti ad altro titolo in altri progetti
SELECT i.nome, i.cognome, i.stipendio FROM progetto p JOIN impiegato i ON p.responsabile = i.matricola WHERE p.responsabile NOT IN (SELECT matrimpiegato from coinvolgimento);

-- 3.3) Mostrare: il nome delle divisioni dell'azienda, il nome, cognome e matricola dei loro direttori e la loro percemtuale di tempo che gli stessi spendono in essa
SELECT d.nome AS nomeDivisione, i.nome AS nomeDirettore, i.cognome AS cognomeDirettore, i.matricola AS matricolaDirettore, a.percentualeTempo FROM divisione d JOIN affiliazione a ON d.direttore = a.matricola JOIN impiegato i ON a.matricola = i.matricola;

-- 4) MODIFICARE la base di dati considerando l'abolizione della organizzazione aziendale in divisioni
DROP TABLE divisione;
DROP TABLE affiliazione;