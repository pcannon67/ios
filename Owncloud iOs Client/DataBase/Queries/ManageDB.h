//
//  ManageDB.h
//  Owncloud iOs Client
//
//  Created by Gonzalo Gonzalez on 21/06/13.
//

/*
 Copyright (C) 2014, ownCloud, Inc.
 This code is covered by the GNU Public License Version 3.
 For distribution utilizing Apple mechanisms please see https://owncloud.org/contribute/iOS-license-exception/
 You should have received a copy of this license
 along with this program. If not, see <http://www.gnu.org/licenses/gpl-3.0.en.html>.
 */

#import <Foundation/Foundation.h>

@interface ManageDB : NSObject

/*
 * Method that create a empty data base.
 */
+(void) createDataBase;

/*
 * Delete table of database version
 */
+ (void) insertVersionToDataBase:(int) version;


/*
 * Method that remove a specific table
 * @table -> table to remove
 */
+(void) removeTable:(NSString *) table;

/*
 * This method return if local_folder column exist or not
 */
+(BOOL) isLocalFolderExistOnFiles;

/*
 * This method return the dataBase version
 */

+(int) getDatabaseVersion;

/*
 * Method that make the update the version of the dataBase
 * If the app detect dataBase version 1 launch this method
 * The change is adding the etag column in table files.
 */
+(void) updateDBVersion1To2;


/*
 * This method update the version of the dataBase with version 2 to version 3
 * New changes:
 *  - In users table new field is_server_chunk (BOOL NOT NULL DEFAULT 0)
 */
+(void)updateDBVersion2To3;

/*
 * This method update the version of the dataBase with version 3 to version 4
 * New changes:
 *  - In is_ (BOOL NOT NULL DEFAULT 0)
 */
+(void)updateDBVersion3To4;

/*
 * This method update the version of the dataBase with version 4 to version 5
 * New changes:
 * Shared API Support:
 * files table: shared_by_link (Boolean) & shared_by_user (Boolean) & shared_by_group (Boolean) & public_link (String) fields
 * files_backup table: shared_by_link (Boolean) & shared_by_user (Boolean) & shared_by_group (Boolean) & public_link (String) fields
 */
+(void)updateDBVersion4To5;

///-----------------------------------
/// @name Update Database version with 5 verstion to 6 version
///-----------------------------------

/**
 * Changes:
 *
 * 1.- Fix the problems in previous versions with Path without fathers
 *
 */
+ (void) updateDBVersion5To6;

///-----------------------------------
/// @name Update Database version with 6 verstion to 7 version
///-----------------------------------

/**
 * Changes:
 *
 * Has been included a new field on the uploads_offline file for to store the task identifier: task_identifier field
 *
 */
+ (void) updateDBVersion6To7;


///-----------------------------------
/// @name Update Database version with 7 version to 8 version
///-----------------------------------

/**
 * Changes:
 *
 * Has been included a new field for store the permissions of the file
 *
 */
+ (void) updateDBVersion7To8;

///-----------------------------------
/// @name Update Database version with 8 version to 9 version
///-----------------------------------

/**
 * Changes:
 *
 * Has been included a new field has_cookies_support for store if the server of the user support cookies
 * Has been included a new filed for store task identifier for Downloads in background
 *
 */

+ (void) updateDBVersion8To9;

///-----------------------------------
/// @name Update Database version with 9 version to 10
///-----------------------------------

/**
 * Changes:
 *
 * Migrate the current usersname and password stored in users table to the new keychain
 * Do a backup of the users table in users_backup table
 * Remove users table
 * Create a new users table without username and password
 * Migrate from users_backup table to new users table
 */
+ (void) updateDBVersion9To10;

@end