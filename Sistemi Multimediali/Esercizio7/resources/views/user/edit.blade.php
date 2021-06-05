@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Modifica il tuo profilo')
@section('page_description', 'Modifica il tuo profilo qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">Modifica il tuo profilo</h1></div>
                    <div class="card-body">
                        <form action="/user/{{$user -> id}}" method="post" enctype="multipart/form-data"
                              autocomplete="off">
                            @csrf
                            @method('PUT')
                            <div class="form-group">
                                <label for="name">Nome</label>
                                <input type="text" class="form-control{{$errors->has('name')? ' border-danger':''}}"
                                       id="name"
                                       name="name"
                                       placeholder="Inserisci qui il tuo nome"
                                       value="{{old('name') ?? $user->name}}">
                                <small class="alert-danger">{{$errors->first('name')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="email">Email</label>
                                <input type="text" class="form-control{{$errors->has('email')? ' border-danger':''}}"
                                       id="email"
                                       name="email"
                                       placeholder="Inserisci qui la tua email"
                                       value="{{old('email') ?? $user->email}}">
                                <small class="alert-danger">{{$errors->first('email')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="motto">Motto</label>
                                <input type="text" class="form-control{{$errors->has('motto')? ' border-danger':''}}"
                                       id="motto"
                                       name="motto"
                                       placeholder="Inserisci qui il tuo motto"
                                       value="{{old('motto') ?? $user->motto}}">
                                <small class="alert-danger">{{$errors->first('motto')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="about_me">Su di me:</label>
                                <textarea class="form-control{{$errors->has('about_me')? ' border-danger':''}}"
                                          id="about_me" name="about_me" rows="5"
                                          placeholder="Inserisci qui informazioni su di te">{{old('about_me') ?? $user->about_me}}
                                </textarea>
                                <small class="alert-danger">{{$errors->first('about_me')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="image">Foto del profilo</label>
                                <input type="file" class="form-control{{$errors->has('image')? ' border-danger':''}}"
                                       id="image" name="image" value="">
                                <small class="alert-danger">{{$errors->first('image')}}</small>
                            </div>
                            @if(file_exists('img/users/' . $user->id . '_large.jpg'))
                                <div class="mb-2">
                                    <img style="max-width: 400px; max-height: 300px;"
                                         src="/img/users/{{$user->id}}_large.jpg" alt="Foto del profilo">
                                    <a class="btn btn-outline-danger float-right"
                                       href="/user/delete_images/{{$user->id}}">Elimina l'immagine</a>
                                </div>
                            @endif
                            <input class="btn btn-primary mt-4" type="submit" value="Aggiorna il tuo profilo">
                        </form>
                        <a class="btn btn-primary float-right" href="{{\Illuminate\Support\Facades\URL::previous()}}"><i
                                class="fas fa-arrow-circle-up"></i>
                            Indietro</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection
