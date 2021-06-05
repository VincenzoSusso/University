<?php

namespace App\Http\Controllers;

use App\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Gate;
use Intervention\Image\Facades\Image;

class UserController extends Controller
{
    public function __construct()
    {
        $this->middleware('auth')->except(['show']);
    }

    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        //
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param \Illuminate\Http\Request $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     *
     * @param \App\User $user
     * @return \Illuminate\Http\Response
     */
    public function show(User $user)
    {
        return view('user.show')->with([
            'user' => $user,
        ]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param \App\User $user
     * @return \Illuminate\Http\Response
     */
    public function edit(User $user)
    {
        abort_unless(Gate::allows('update', $user), 403);

        return view('user/edit')->with([
            'user' => $user,
        ]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param \Illuminate\Http\Request $request
     * @param \App\User $user
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, User $user)
    {
        abort_unless(Gate::allows('update', $user), 403);

        $request->validate([
            'name' => 'required',
            'email' => 'required|email:rfc',
            'image' => 'mimes:jpeg,jpg,png',
        ]);

        if ($request['email'] !== $user->email) {
            $request->validate([
                'email' => 'unique:users,email',
            ]);
        }

        $user->update([
            'name' => $request['name'],
            'email' => $request['email'],
            'motto' => $request['motto'],
            'about_me' => $request['about_me'],
        ]);

        if ($request['image']) {
            $this->saveImages($request['image'], $user->id);
        }

        return redirect('/')->with([
            'message_success' => 'Le informazione dell\'utente "' . $user->name . '" sono state modificate',
        ]);
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param \App\User $user
     * @return \Illuminate\Http\Response
     */
    public function destroy(User $user)
    {
        abort_unless(Gate::allows('delete', $user), 403);
    }

    private function saveImages($imageInput, $user_id)
    {
        $localPath = '/img/users/';

        $image = Image::make($imageInput);
        if ($image->width() > $image->height()) {
            // Landscape

            $image->widen(1200)
                ->save(public_path() . $localPath . $user_id . '_large.jpg');

            Image::make($imageInput)->widen(60)
                ->save(public_path() . $localPath . $user_id . '_thumb.jpg');

            Image::make($imageInput)->widen(400)
                ->pixelate(12)
                ->save(public_path() . $localPath . $user_id . '_pixelated.jpg');
        } else {
            // Portrait

            $image->heighten(900)
                ->save(public_path() . $localPath . $user_id . '_large.jpg');

            Image::make($imageInput)->heighten(60)
                ->save(public_path() . $localPath . $user_id . '_thumb.jpg');

            Image::make($imageInput)->heighten(400)
                ->pixelate(12)
                ->save(public_path() . $localPath . $user_id . '_pixelated.jpg');
        }
    }

    private function deleteImages($user_id)
    {
        $localPath = '/img/users/';

        if (file_exists(public_path() . $localPath . $user_id . '_large.jpg')) {
            unlink(public_path() . $localPath . $user_id . '_large.jpg');
        }

        if (file_exists(public_path() . $localPath . $user_id . '_thumb.jpg')) {
            unlink(public_path() . $localPath . $user_id . '_thumb.jpg');
        }

        if (file_exists(public_path() . $localPath . $user_id . '_pixelated.jpg')) {
            unlink(public_path() . $localPath . $user_id . '_pixelated.jpg');
        }
    }

    public function deleteImagesView($user_id)
    {
        $this->deleteImages($user_id);

        return redirect('/user/' . $user_id . '/edit')->with([
            'message_success' => 'L\'immagine dell\'utente è stata eliminata'
        ]);
    }
}
