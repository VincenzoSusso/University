-- 1) Creare la base di dati e le rispettive tabelle avendo cura di definirne i vincoli
CREATE SCHEMA cineteca;

USE cineteca;

CREATE TABLE attore(
	codattore INT PRIMARY KEY,
	nome VARCHAR(30),
	cogn VARCHAR(30),
	datanascita DATE
);

CREATE TABLE cantante(
	codcantante INT PRIMARY KEY,
	nome VARCHAR(30),
	cogn VARCHAR(30),
	datanascita DATE
);

CREATE TABLE film(
	cod INT PRIMARY KEY,
	titolo VARCHAR(50) NOT NULL,
	regista VARCHAR(50),
	anno DATE
);

CREATE TABLE film_attore(
	codfilm INT REFERENCES film(cod),
	codattore INT REFERENCES attore(codattore),

	PRIMARY KEY(codfilm, codattore)
);

-- Popolare la base di dati con un numero significativo (es. 5) di istanze per tabella avendo cura di non rappresentare solo situazioni particolari (es. un solo film)
INSERT INTO attore VALUES(0, "Pippo", "Pluto", "1980-05-18");
INSERT INTO attore VALUES(1, "Vincenzo", "Susso", "1999-11-15");
INSERT INTO attore VALUES(2, "Robert", "De Niro", "1950-02-01");
INSERT INTO attore VALUES(3, "Tony", "Montana", "1968-12-03");
INSERT INTO attore VALUES(4, "Salvatore", "Esposito", "1971-09-26");
INSERT INTO attore VALUES(5, "Gennaro", "Bullo", "1985-04-24");

INSERT INTO cantante VALUES(0, "Amy", "Lee", "1980-05-17");
INSERT INTO cantante VALUES(1, "Amy", "Winehouse", "1975-04-04");
INSERT INTO cantante VALUES(2, "Axl", "Rose", "1965-09-11");
INSERT INTO cantante VALUES(3, "Vincenzo", "Susso", "1999-11-15");
INSERT INTO cantante VALUES(4, "Tame", "Impala", "1981-10-24");

INSERT INTO film VALUES(0, "C'era una volta a Hollywood...", "Quentin Tarantino", "2019-02-14");
INSERT INTO film VALUES(1, "C'era una volta in America", "Sergio Leone", "1970-06-15");
INSERT INTO film VALUES(2, "Taxi Driver", "Martin Scorsese", "1970-09-01");
INSERT INTO film VALUES(3, "Pulp Fiction", "Quentin Tarantino", "1999-03-20");
INSERT INTO film VALUES(4, "La La Land", "Damien Chazelle", "2000-01-01");

INSERT INTO film_attore VALUES(4, 0);
INSERT INTO film_attore VALUES(2, 0);
INSERT INTO film_attore VALUES(2, 1);
INSERT INTO film_attore VALUES(0, 4);
INSERT INTO film_attore VALUES(1, 4);
INSERT INTO film_attore VALUES(3, 5);

/*
	TEST

	SELECT * FROM attore a JOIN film_attore fa ON a.codattore = fa.codattore JOIN film f ON fa.codfilm = f.cod;
*/


-- 3) Scrivere le query SQL in grado di soddisfare le seguenti richieste:

-- 3.1) Mostrare Titolo, Regista e Cast dei relativi Attori(ovvero nome, cognome e data di nascita di tutti gli attori che hanno recitato in un film) dei film realizzati nel 2000
SELECT f.titolo, f.regista, f.anno, a.nome, a.cogn, a.dataNascita FROM film f JOIN film_attore fa ON f.cod = fa.codfilm JOIN attore a ON fa.codattore = a.codattore WHERE (f.anno >= "2000-01-01" AND f.anno <= "2000-12-31");

-- 3.2) Trovare Nome e Cognome di coloro i quali hanno recitato in non più di un film
SELECT DISTINCT a.nome, a.cogn FROM attore a LEFT JOIN film_attore fa ON a.codattore = fa.codattore GROUP BY a.codattore HAVING count(a.codattore) <= 1;

-- 3.3) Trovare nome e cognome di coloro i quali nella loro carriera sono stati attori e cantanti
SELECT a.nome, a.cogn FROM attore a, cantante c WHERE a.nome = c.nome AND a.cogn = c.cogn AND a.datanascita = c.datanascita;

-- 4) Modificare la base di dati per consentire di specificare l'esistenza di più di un regista per un film
CREATE TABLE regista(
	codregista INT PRIMARY KEY,
	nome VARCHAR(25),
	cogn VARCHAR(25)
);

CREATE TABLE film_regista(
	codregista INT REFERENCES regista(codregista),
	codFilm INT REFERENCES film(cod),

	PRIMARY KEY(codregista, codfilm)
);

ALTER TABLE film DROP COLUMN regista;

INSERT INTO regista VALUES(0, "Quantin", "Tarantino");
INSERT INTO regista VALUES(1, "Sergio", "Leone");
INSERT INTO regista VALUES(2, "Martin", "Scorsese");
INSERT INTO regista VALUES(3, "Damien", "Chazelle");

INSERT INTO film_regista VALUES(0, 0);
INSERT INTO film_regista VALUES(1, 1);
INSERT INTO film_regista VALUES(2, 2);
INSERT INTO film_regista VALUES(0, 3);
INSERT INTO film_regista VALUES(3, 4);

/*
	TEST

	SELECT * FROM film f JOIN film_regista fr ON f.cod = fr.codfilm JOIN regista r ON fr.codregista = r.codregista;
*/