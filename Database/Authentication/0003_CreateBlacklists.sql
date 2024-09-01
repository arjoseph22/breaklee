CREATE TABLE Blacklists (
    ID INT NOT NULL AUTO_INCREMENT,
    AccountID INT,
    AddressIP VARCHAR(45),
    Description VARCHAR(255) NOT NULL,
    CreatedAt BIGINT UNSIGNED NOT NULL DEFAULT UNIX_TIMESTAMP(CURRENT_TIMESTAMP),
    UpdatedAt BIGINT UNSIGNED NOT NULL DEFAULT UNIX_TIMESTAMP(CURRENT_TIMESTAMP),

    PRIMARY KEY (ID)
) ENGINE = INNODB DEFAULT CHARSET = utf8;