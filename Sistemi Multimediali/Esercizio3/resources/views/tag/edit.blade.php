@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Modifica Tag')
@section('page_description', 'Modifica un Tag qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header">Modifica il tag "{{$tag -> name}}"</div>
                    <div class="card-body">
                        <form action="/tag/{{$tag -> id}}" method="post">
                            @csrf
                            @method('PUT')
                            <div class="form-group">
                                <label for="name">Nome</label>
                                <input type="text" class="form-control{{$errors->has('name')? ' border-danger':''}}"
                                       id="name"
                                       name="name"
                                       placeholder="Inserisci qui il nome del tag"
                                       value={{old('name') ?? $tag->name}}>
                                <small class="alert-danger">{{$errors->first('name')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="style">Colore del Tag</label>
                                <input type="color" id="style" name="color"
                                       value="{{isset($tag -> color) ? ('#' . $tag -> color) : ''}}">
                            </div>
                            <input class="btn btn-primary mt-4" type="submit" value="Aggiorna il tag">
                        </form>
                        <a class="btn btn-primary float-right" href="/tag"><i class="fas fa-arrow-circle-up"></i>
                            Indietro</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection
