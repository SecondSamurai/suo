-- MySQL dump 10.13  Distrib 8.0.32, for Win64 (x86_64)
--
-- Host: localhost    Database: zp
-- ------------------------------------------------------
-- Server version	8.0.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `выполнение работы`
--

DROP TABLE IF EXISTS `выполнение работы`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `выполнение работы` (
  `ID работы` int NOT NULL,
  `ID трудоустройства` int DEFAULT NULL,
  `Кол-во часов` int DEFAULT NULL,
  `Дата приступления к задаче` date DEFAULT NULL,
  `Дата выполнения` date DEFAULT NULL,
  PRIMARY KEY (`ID работы`),
  KEY `ID трудоустройства_idx` (`ID трудоустройства`),
  CONSTRAINT `ID трудоустройства` FOREIGN KEY (`ID трудоустройства`) REFERENCES `трудоустройство` (`ID трудоустройства`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `выполнение работы`
--

LOCK TABLES `выполнение работы` WRITE;
/*!40000 ALTER TABLE `выполнение работы` DISABLE KEYS */;
/*!40000 ALTER TABLE `выполнение работы` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `данные сотрудника`
--

DROP TABLE IF EXISTS `данные сотрудника`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `данные сотрудника` (
  `ID сотрудника` int NOT NULL,
  `ФИО` varchar(45) DEFAULT NULL,
  `Дата рождения` date DEFAULT NULL,
  `Общий стаж работы` int DEFAULT NULL,
  PRIMARY KEY (`ID сотрудника`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `данные сотрудника`
--

LOCK TABLES `данные сотрудника` WRITE;
/*!40000 ALTER TABLE `данные сотрудника` DISABLE KEYS */;
/*!40000 ALTER TABLE `данные сотрудника` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `данные сотрудников`
--

DROP TABLE IF EXISTS `данные сотрудников`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `данные сотрудников` (
  `ID сотрудника` int NOT NULL,
  `Фамилия` varchar(25) DEFAULT NULL,
  `Имя` varchar(25) DEFAULT NULL,
  `Отчество` varchar(25) DEFAULT NULL,
  `Должность` varchar(99) DEFAULT NULL,
  `ДатаРождения` date DEFAULT NULL,
  `НомерТелефона` varchar(20) DEFAULT NULL,
  `Адрес` varchar(45) DEFAULT NULL,
  `ОбщийсСтажРаботы` int DEFAULT NULL,
  `ДатаНайма` date DEFAULT NULL,
  PRIMARY KEY (`ID сотрудника`),
  UNIQUE KEY `ID сотрудника_UNIQUE` (`ID сотрудника`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `данные сотрудников`
--

LOCK TABLES `данные сотрудников` WRITE;
/*!40000 ALTER TABLE `данные сотрудников` DISABLE KEYS */;
INSERT INTO `данные сотрудников` VALUES (1,'Ежов','Макар','Сергеевич','Глава СБ','1989-05-23','+79585961238','д.Крутой овраг',2,'2020-08-16'),(2,'Варягина','Дарья','Александровна','Глава отдела МСВиУ','1995-03-05','+79835652357','г.Йошкар-Ола',7,'2019-05-30'),(3,'Круглов','Николай','Павлович','Глава отдела БОБР','1987-08-11','+79746345721','г.Йошкар-Ола',12,'2023-11-12');
/*!40000 ALTER TABLE `данные сотрудников` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `должность`
--

DROP TABLE IF EXISTS `должность`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `должность` (
  `ID должности` int NOT NULL,
  `Должность` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID должности`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `должность`
--

LOCK TABLES `должность` WRITE;
/*!40000 ALTER TABLE `должность` DISABLE KEYS */;
/*!40000 ALTER TABLE `должность` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `история стоимости оплаты труда`
--

DROP TABLE IF EXISTS `история стоимости оплаты труда`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `история стоимости оплаты труда` (
  `ID оплаты труда` int NOT NULL,
  `Должность` varchar(45) DEFAULT NULL,
  `Оплата за час труда в этой должности` int DEFAULT NULL,
  `Дата изменения стоимости оплаты труда` date DEFAULT NULL,
  PRIMARY KEY (`ID оплаты труда`),
  KEY `Должность_idx` (`Должность`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `история стоимости оплаты труда`
--

LOCK TABLES `история стоимости оплаты труда` WRITE;
/*!40000 ALTER TABLE `история стоимости оплаты труда` DISABLE KEYS */;
/*!40000 ALTER TABLE `история стоимости оплаты труда` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `пользователи`
--

DROP TABLE IF EXISTS `пользователи`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `пользователи` (
  `id пользователя` int NOT NULL AUTO_INCREMENT,
  `логин пользователя` varchar(32) DEFAULT NULL,
  `пароль` varchar(9) DEFAULT NULL,
  `ФИО` varchar(99) DEFAULT NULL,
  `роль пользователя` varchar(1) DEFAULT NULL,
  PRIMARY KEY (`id пользователя`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `пользователи`
--

LOCK TABLES `пользователи` WRITE;
/*!40000 ALTER TABLE `пользователи` DISABLE KEYS */;
INSERT INTO `пользователи` VALUES (1,'gregor_sin','123456','Русаков Григорий Степанович','1'),(2,'elena_valkyrie','112233','Шолохова Елена Сергеевна','2'),(3,'lil_max','123123','Огузков Максим Степанович','3'),(4,'V','002077','Сереброрукова Валерия ','3');
/*!40000 ALTER TABLE `пользователи` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `сотрудники`
--

DROP TABLE IF EXISTS `сотрудники`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `сотрудники` (
  `КодСотрудника` int NOT NULL AUTO_INCREMENT,
  `Фамилия` varchar(20) DEFAULT NULL,
  `Имя` varchar(20) DEFAULT NULL,
  `Должность` varchar(20) DEFAULT NULL,
  `Обращение` varchar(20) DEFAULT NULL,
  `ДатаРождения` date DEFAULT NULL,
  `ДатаНайма` date DEFAULT NULL,
  `Адрес` varchar(20) DEFAULT NULL,
  `Город` varchar(20) DEFAULT NULL,
  `Область` varchar(10) DEFAULT NULL,
  `Индекс` varchar(20) DEFAULT NULL,
  `Страна` varchar(20) DEFAULT NULL,
  `ДомашнийТелефон` varchar(20) DEFAULT NULL,
  `Добавочный` varchar(20) DEFAULT NULL,
  `Фотография` blob,
  `Примечания` varchar(20) DEFAULT NULL,
  `Подчиняется` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`КодСотрудника`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `сотрудники`
--

LOCK TABLES `сотрудники` WRITE;
/*!40000 ALTER TABLE `сотрудники` DISABLE KEYS */;
/*!40000 ALTER TABLE `сотрудники` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `трудоустройство`
--

DROP TABLE IF EXISTS `трудоустройство`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `трудоустройство` (
  `ID трудоустройства` int NOT NULL,
  `ID сотрудника` int DEFAULT NULL,
  `ID должности` int DEFAULT NULL,
  `Дата принятия` date DEFAULT NULL,
  `Дата увольнения` date DEFAULT NULL,
  PRIMARY KEY (`ID трудоустройства`),
  KEY `ID сотрудника_idx` (`ID сотрудника`),
  KEY `ID должности_idx` (`ID должности`),
  CONSTRAINT `ID должности` FOREIGN KEY (`ID должности`) REFERENCES `данные сотрудника` (`ID сотрудника`),
  CONSTRAINT `ID сотрудника` FOREIGN KEY (`ID сотрудника`) REFERENCES `должность` (`ID должности`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `трудоустройство`
--

LOCK TABLES `трудоустройство` WRITE;
/*!40000 ALTER TABLE `трудоустройство` DISABLE KEYS */;
/*!40000 ALTER TABLE `трудоустройство` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-04-14 12:53:11
