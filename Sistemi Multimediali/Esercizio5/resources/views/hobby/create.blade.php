@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Creazione Hobby')
@section('page_description', 'Crea un nuovo Hobby qui')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-12">
                <div class="card">
                    <div class="card-header"><h1 class="m-0">Crea un nuovo hobby</h1></div>
                    <div class="card-body">
                        <form action="/hobby" method="post">
                            @csrf
                            <div class="form-group">
                                <label for="name">Nome</label>
                                <input type="text" class="form-control{{$errors->has('name')? ' border-danger':''}}"
                                       id="name"
                                       name="name"
                                       placeholder="Inserisci qui il nome dell'hobby" value={{old('name')}}>
                                <small class="alert-danger">{{$errors->first('name')}}</small>
                            </div>
                            <div class="form-group">
                                <label for="description">Descrizione</label>
                                <textarea class="form-control{{$errors->has('description')? ' border-danger':''}}"
                                          id="description" name="description" rows="5"
                                          placeholder="Inserisci qui la descrizione dell'hobby">{{old('description')}}</textarea>
                                <small class="alert-danger">{{$errors->first('description')}}</small>
                            </div>
                            <input class="btn btn-primary mt-4" type="submit" value="Salva l'hobby">
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
