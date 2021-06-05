<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/info', function () {
    return view('info');
});

Auth::routes();

Route::resource('user', 'UserController');
Route::resource('hobby', 'HobbyController');
Route::resource('tag', 'TagController');


Route::get('/', 'HomeController@index')->name('home');
Route::get('/home', 'HomeController@index')->name('home');
Route::get('/user/delete_images/{user_id}', 'UserController@deleteImagesView');
Route::get('/hobby/delete_images/{hobby_id}', 'HobbyController@deleteImagesView');
Route::get('/hobby/tag/{tag_id}', 'HobbyTagController@getFilteredHobbies');
Route::get('/hobby/{hobby_id}/tag/{tag_id}/attach', 'HobbyTagController@attachTag')->middleware('auth');
Route::get('/hobby/{hobby_id}/tag/{tag_id}/detach', 'HobbyTagController@detachTag')->middleware('auth');
