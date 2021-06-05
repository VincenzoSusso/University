@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Modifica Hobby')
@section('page_description', 'Modifica un Hobby qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">Modifica l'hobby "{{$hobby -> name}}"</h1></div>
                    <div class="card-body">
                        <form action="/hobby/{{$hobby -> id}}" method="post" enctype="multipart/form-data"
                              autocomplete="off">
                            @csrf
                            @method('PUT')
                            <div class="form-group">
                                <label for="name">Nome</label>
                                <input type="text" class="form-control{{$errors->has('name')? ' border-danger':''}}"
                                       id="name"
                                       name="name"
                                       placeholder="Inserisci qui il nome dell'hobby"
                                       value="{{old('name') ?? $hobby->name}}">
                                <small class="alert-danger">{{$errors->first('name')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="description">Descrizione</label>
                                <textarea class="form-control{{$errors->has('description')? ' border-danger':''}}"
                                          id="description" name="description" rows="5"
                                          placeholder="Inserisci qui la descrizione dell'hobby">{{old('description') ?? $hobby->description}}</textarea>
                                <small class="alert-danger">{{$errors->first('description')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="image">Foto dell'hobby</label>
                                <input type="file" class="form-control{{$errors->has('image')? ' border-danger':''}}"
                                       id="image" name="image" value="">
                                <small class="alert-danger">{{$errors->first('image')}}</small>
                            </div>
                            @if(file_exists('img/hobbies/' . $hobby->id . '_large.jpg'))
                                <div class="mb-2">
                                    <img style="max-width: 400px; max-height: 300px;"
                                         src="/img/hobbies/{{$hobby->id}}_large.jpg" alt="Foto dell'hobby">
                                    <a class="btn btn-outline-danger float-right"
                                       href="/hobby/delete_images/{{$hobby->id}}">Elimina l'immagine</a>
                                </div>
                            @endif
                            <input class="btn btn-primary mt-4" type="submit" value="Aggiorna l'hobby">
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
